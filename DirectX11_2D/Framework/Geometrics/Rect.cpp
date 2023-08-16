#include "Framework.h"
#include "Rect.h"

Rect::Rect(Vector3 position, Vector3 size, float rotation)
    : position(position), size(size), rotation(rotation)
{
    vertices.assign(4, VertexColor());

    vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
    vertices[1].position = Vector3(+0.5f, +0.5f, 0.0f);
    vertices[2].position = Vector3(+0.5f, -0.5f, 0.0f);
    vertices[3].position = Vector3(-0.5f, +0.5f, 0.0f);

    for (auto& v : vertices)
        v.color = color;

    // 정점 버퍼
    vb = new VertexBuffer();
    vb->Create(vertices, D3D11_USAGE_DYNAMIC);

    // 인덱스 버퍼
    indices = { 0,1,2,0,3,1 };
    ib = new IndexBuffer();
    ib->Create(indices, D3D11_USAGE_IMMUTABLE);

    // 정점 셰이더
    vs = new VertexShader();
    vs->Create(ShaderPath + L"VertexColor.hlsl", "VS");

    // 입력배치
    il = new InputLayout();
    il->Create(VertexColor::descs, VertexColor::count, vs->GetBlob());

    // 픽셀 셰이더
    ps = new PixelShader();
    ps->Create(ShaderPath + L"VertexColor.hlsl", "PS");

    // 월드 버퍼
    wb = new WorldBuffer();

    box = new BoundingBox(position, size, rotation, Color(1, 0, 0, 1), CENTER);
}

Rect::~Rect()
{
    // 생성의 역순
    SAFE_DELETE(wb);
    SAFE_DELETE(ps);
    SAFE_DELETE(il);
    SAFE_DELETE(vs);
    SAFE_DELETE(ib);
    SAFE_DELETE(vb);
}

void Rect::Update()
{
    // world view projection
    // Size
    D3DXMatrixScaling(&S, size.x, size.y, size.z);
    // Rotation
    D3DXMatrixRotationZ(&R, rotation);
    // Translation (position)
    D3DXMatrixTranslation(&T, position.x, position.y, position.z);

    // 월드 버퍼
    world = S * R * T;
    wb->SetWorld(world);
}

void Rect::Render()
{
    // IA
    vb->SetIA();
    ib->SetIA();
    il->SetIA();
    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    // VS
    vs->SetShader();
    wb->SetVSBuffer(0);

    // PS
    ps->SetShader();

    // OM
    DC->DrawIndexed(ib->GetCount(), 0, 0);
}

void Rect::GUI()
{
    using namespace ImGui;
    Begin("Rect");
    {
        InputFloat3("Pos", position, 2);
        InputFloat3("Size", size, 2);
        SliderAngle("Rot", &rotation, 0, 360.0f);

        if (ColorPicker4("Color", color))
            UpdateColor();
    }
    End();
}

void Rect::UpdateColor()
{
    // 매핑 작업
    D3D11_MAPPED_SUBRESOURCE subResource;
    DC->Map(vb->GetResource(), 0, D3D11_MAP_WRITE_DISCARD, 0, &subResource);
    {
        for (auto& v : vertices)
            v.color = color;

        memcpy(subResource.pData, vertices.data(), vb->GetCount() * vb->GetStride());
    }
    DC->Unmap(vb->GetResource(), 0);
}

