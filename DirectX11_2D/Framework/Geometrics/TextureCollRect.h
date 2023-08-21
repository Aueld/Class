#pragma once

class TextureCollRect
{
public:
    TextureCollRect(Vector3 position, Vector3 size, float rotation, wstring path, Pivot pivot, float velo);
    TextureCollRect(Vector3 position, Vector3 size, float rotation);
    virtual ~TextureCollRect();

    void Update();
    void Render();
    void GUI();

    void SetShader(wstring shaderPath);
    void SetSRV(ID3D11ShaderResourceView* srv) { this->srv = srv; }

    void Gravity();
    void Jump();
    void Move();

    BoundingBox* GetBox() { return this->box; }
    BoundingBox* GetPlat() { return this->plat; }

    Vector3 GetPos() { return this->position; }

    int GetJumpCount() { return this->jumpCount; }
    void JumpCountPlus() { this->jumpCount++; }
    void ResetJumpCount() { this->jumpCount = 0; }
    void ResetRandPos();

    void TotalScore();

    void OnBox(TextureCollRect* ch);

private:
    void SetVertices();
    void UpdateWorld();

protected:
    vector<VertexTexture> vertices;
    VertexBuffer* vb = nullptr;

    vector<uint> indices;
    IndexBuffer* ib = nullptr;

    InputLayout* il = nullptr;

    VertexShader* vs = nullptr;
    PixelShader* ps = nullptr;

    Matrix world, S, R, T;

    WorldBuffer* wb = nullptr;

    Vector3 position;
    Vector3 size;
    float rotation;

    Pivot pivot = CENTER;

    ID3D11ShaderResourceView* srv = nullptr;

    BoundingBox* box = nullptr;
    BoundingBox* plat = nullptr;

    float velocityY;

    int jumpCount = 0;
    float score = 1;
};
