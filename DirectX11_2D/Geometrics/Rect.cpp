#include "Framework.h"
#include "Rect.h"

Rect::Rect(Vector3 position, Vector3 size, float rotation)
	: position(position), size(size), rotation(rotation)
{
	// 정점 버퍼 생성
	vertices.assign(4, VertexColor());
	vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[1].position = Vector3-0.5f, 0.5f, 0.0f);
	vertices[2].position = Vector3(0.5f, -0.5f, 0.0f);
	vertices[3].position = Vector3(-0.5f, 0.5f, 0.0f);

	for (auto v : vertices)
	{
		v.color = color;
	}

	vb = new VertexBuffer();
	vb->Create(vertices, D3D11_USAGE_DYNAMIC);

	// 인덱스 버퍼 생성
	indices = { 0,1,2 ,0,3,1 };
	ib = new IndexBuffer();
	ib->Create(indices, D3D11_USAGE_IMMUTABLE);

	// 정점 셰이더 생성
	vs = new VertexShader();
	vs->Create(ShaderPath + L"VertexColor.hlsl", "VS");

	il = new InputLayout();
	il->Create(VertexColor::descs, VertexColor::count, vs->GetBlob());

	// 픽셀 셰이더 생성
	ps = new PixelShader();
	ps->Create(ShaderPath + L"VertexColor.hlsl", "PS");

	wb = new WorldBuffer();
}

Rect::~Rect()
{

}

void Rect::Update()
{

}

void Rect::Render()
{

}
