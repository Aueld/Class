#include "Framework.h"
#include "BoundingBox.h"

BoundingBox::BoundingBox(Vector3 position, Vector3 size, float rotation, Color color, Pivot pivot)
{
	edge = new RectEdge();

    SetVertices();

    // 정점 버퍼
    vb = new VertexBuffer();
    vb->Create(vertices, D3D11_USAGE_DYNAMIC);
    
    // 인덱스 버퍼
    ib = new IndexBuffer();
    indices = { 0,1,2,0,3,1 };
    ib->Create(indices, D3D11_USAGE_IMMUTABLE);

    // 정점 셰이더
    vs = new VertexShader();
    vs->Create(ShaderPath + L"CollisionShader.hlsl", "VS");

    // 픽셀 셰이더
    ps = new PixelShader();
    ps->Create(ShaderPath + L"CollisionShader.hlsl", "PS");

    // 입력배치
    il = new InputLayout();
    il->Create(VertexColor::descs, VertexColor::count, vs->GetBlob());

    // 월드 버퍼
    wb = new WorldBuffer();

    
}

BoundingBox::~BoundingBox()
{
    SAFE_DELETE(wb);
    SAFE_DELETE(il);
    SAFE_DELETE(ps);
    SAFE_DELETE(vs);
    SAFE_DELETE(ib);
    SAFE_DELETE(vb);
    SAFE_DELETE(edge);
}

void BoundingBox::Update(Vector3 position, Vector3 size, float rotation)
{
    this->position = position;
    this->size = size;
    this->rotation = rotation;

    D3DXMatrixScaling(&S, size.x, size.y, size.z);
    D3DXMatrixRotationZ(&R, rotation);
    D3DXMatrixTranslation(&T, position.x, position.y, position.z);

    world = S * R * T;

    wb->SetWorld(world);

    UpdateCollisionData();
}

void BoundingBox::Render()
{
    // IA
    vb->SetIA();
    ib->SetIA();
    il->SetIA();
    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    // VS
    vs->SetShader();

    // PS
    ps->SetShader();
    wb->SetVSBuffer(0);

    // OM
    DC->DrawIndexed(ib->GetCount(), 0, 0);
}

bool BoundingBox::AABB(BoundingBox * a, BoundingBox * b)
{
	return false;
}

void BoundingBox::SetVertices()
{
    vertices.assign(4, VertexColor());

    switch (pivot)
    {
    case CENTER:
        vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
        vertices[1].position = Vector3(+0.5f, +0.5f, 0.0f);
        vertices[2].position = Vector3(+0.5f, -0.5f, 0.0f);
        vertices[3].position = Vector3(-0.5f, +0.5f, 0.0f);
        break;
    case LEFT:
        vertices[0].position = Vector3(+0.0f, -0.5f, 0.0f);
        vertices[1].position = Vector3(+1.0f, +0.5f, 0.0f);
        vertices[2].position = Vector3(+1.0f, -0.5f, 0.0f);
        vertices[3].position = Vector3(+0.0f, +0.5f, 0.0f);
        break;
    case RIGHT:
        vertices[0].position = Vector3(-1.0f, -0.5f, 0.0f);
        vertices[1].position = Vector3(+0.0f, +0.5f, 0.0f);
        vertices[2].position = Vector3(+0.0f, -0.5f, 0.0f);
        vertices[3].position = Vector3(-1.0f, +0.5f, 0.0f);
        break;
    case UP:
        vertices[0].position = Vector3(-0.5f, -1.0f, 0.0f);
        vertices[1].position = Vector3(+0.5f, +0.0f, 0.0f);
        vertices[2].position = Vector3(+0.5f, -1.0f, 0.0f);
        vertices[3].position = Vector3(-0.5f, +0.0f, 0.0f);
        break;
    case DOWN:
        vertices[0].position = Vector3(-0.5f, +0.0f, 0.0f);
        vertices[1].position = Vector3(+0.5f, +1.0f, 0.0f);
        vertices[2].position = Vector3(+0.5f, +0.0f, 0.0f);
        vertices[3].position = Vector3(-0.5f, +1.0f, 0.0f);
        break;
    }

    for (auto& v : vertices)
        v.color = color;
}

void BoundingBox::UpdateCollisionData()
{
    D3DXVec3TransformCoord(&edge->LT, &vertices[3].position, &world);
    D3DXVec3TransformCoord(&edge->LB, &vertices[0].position, &world);
    D3DXVec3TransformCoord(&edge->RT, &vertices[1].position, &world);
    D3DXVec3TransformCoord(&edge->RB, &vertices[2].position, &world);
}
