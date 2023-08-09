#pragma once

class TextureRect
{
public:
    enum Pivot
    {
        CENTER = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

public:
	TextureRect(Vector3 position, Vector3 size, float rotation, wstring path, Pivot pivot = CENTER);
	virtual ~TextureRect();

    void Update();

    void Render();
    void GUI();

protected:
    Pivot pivot;

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

