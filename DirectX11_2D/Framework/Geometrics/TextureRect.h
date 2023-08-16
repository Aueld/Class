#pragma once

class TextureRect
{
public:
	TextureRect(Vector3 position, Vector3 size, float rotation, wstring path, Pivot pivot = CENTER);
    TextureRect(Vector3 position, Vector3 size, float rotation);
    virtual ~TextureRect();

    void Update();

    void Render();
    void GUI();

    void SetShader(wstring ShaderPath);
    void SetSRV(ID3D11ShaderResourceView* srv) { this->srv = srv; }

protected:
    Pivot pivot = Pivot::CENTER;

	vector<VertexTexture> vertices;
	VertexBuffer* vb = nullptr;

	vector<uint> indices;
	IndexBuffer* ib = nullptr;

    InputLayout* il;

    VertexShader* vs;
    PixelShader* ps;

    WorldBuffer* wb;
    Matrix world, S, R, T;

    Vector3 position;
    Vector3 size;
    float rotation;

    ID3D11ShaderResourceView* srv = nullptr;

private:
    void UpdateWorld();
    void SetVertices();
};

