#pragma once
class Rect
{
public:
	Rect(Vector3 position, Vector3 size, float rotation);
	~Rect();

	void Update();
	void Render();

private:
	vector<VertexColor> vertices;
	VertexBuffer* vb;

	vector<uint> indices;
	IndexBuffer* ib;

	InputLayout* il;

	VertexShader* vs;
	PixelShader* ps;

	WorldBuffer* wb;
	Matrix world, S, R, t;

	Vector3 position;
	Vector3 size;
	float rotation;	// 2d 이므로 한 축으로만 회전

	Color color = Color(1, 0, 0, 1);

};

