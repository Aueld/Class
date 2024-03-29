#pragma once

class Rect
{
public:
    Rect(Vector3 position, Vector3 size, float rotation);
    ~Rect();

    void Update();
    void Render();

    void SetColor(Color color);

    void GUI();

    BoundingBox* GetBox() { return box; }

    void Move();

private:
    void UpdateColor();

private:
    vector<VertexColor> vertices;
    VertexBuffer* vb;

    vector<uint> indices;
    IndexBuffer* ib;

    InputLayout* il;

    VertexShader* vs;
    PixelShader* ps;

    WorldBuffer* wb;
    Matrix world, S, R, T;

    Vector3 position;
    Vector3 size;
    float rotation;

    Color color = Color(1, 0, 0, 1);

    BoundingBox* box = nullptr;
};
