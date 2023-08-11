#include "Framework.h"
#include "TextureRect.h"

TextureRect::TextureRect(Vector3 position, Vector3 size, float rotation, wstring path, Pivot pivot)
	: position(position), size(size), rotation(rotation), pivot(pivot)
{
    SetVertices();

    //{   // 마름모
    //    vertices.assign(4, VertexTexture());

    //    vertices[0].position = Vector3(-0.5f, +0.0f, 0.0f);
    //    vertices[1].position = Vector3(+0.0f, +0.5f, 0.0f);
    //    vertices[2].position = Vector3(+0.5f, +0.0f, 0.0f);
    //    vertices[3].position = Vector3(+0.0f, -0.5f, 0.0f);

    //    vertices[0].uv = Vector2(0, 0.5);
    //    vertices[1].uv = Vector2(0.5, 0);
    //    vertices[2].uv = Vector2(1, 0.5);
    //    vertices[3].uv = Vector2(0.5, 1);
    //}

    // 정점 버퍼
    vb = new VertexBuffer();
    vb->Create(vertices, D3D11_USAGE_DYNAMIC);
    
    // 인덱스 버퍼
    indices = { 0,1,2,0,3,1 };
    //indices = { 0,1,2,0,2,3 };

    ib = new IndexBuffer();
    ib->Create(indices, D3D11_USAGE_IMMUTABLE);

    // 정점 셰이더
    vs = new VertexShader();
    vs->Create(ShaderPath + L"VertexTexture.hlsl", "VS");

    // 픽셀 셰이더
    ps = new PixelShader();
    ps->Create(ShaderPath + L"VertexTexture.hlsl", "PS");

    // 입력배치
    il = new InputLayout();
    il->Create(VertexTexture::descs, VertexTexture::count, vs->GetBlob());


    // 월드 버퍼
    wb = new WorldBuffer();

    
    // SRV, 텍스처
    HRESULT hr = D3DX11CreateShaderResourceViewFromFile
    (
        DEVICE,
        path.c_str(),
        nullptr,
        nullptr,
        &srv,
        nullptr
    );
    CHECK(hr);  // CHECK에서 문제 생길시 경로 문제
}

TextureRect::~TextureRect()
{
    SAFE_DELETE(wb);
    SAFE_DELETE(ps);
    SAFE_DELETE(il);
    SAFE_DELETE(vs);
    SAFE_DELETE(ib);
    SAFE_DELETE(vb);
}

void TextureRect::Update()
{
    UpdateWorld();
}

void TextureRect::UpdateWorld()
{
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

void TextureRect::Render()
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

    DC->PSSetShaderResources(0, 1, &srv);

    // OM
    DC->DrawIndexed(ib->GetCount(), 0, 0);
}

void TextureRect::GUI()
{

}

void TextureRect::SetShader(wstring shaderPath)
{
    vs->Clear();
    ps->Clear();
    vs->Create(ShaderPath + shaderPath, "VS");
    ps->Create(ShaderPath + shaderPath, "PS");
}

void TextureRect::SetVertices()
{
    vertices.assign(4, VertexTexture());

    switch (pivot)
    {
    case TextureRect::CENTER:
        vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
        vertices[1].position = Vector3(+0.5f, +0.5f, 0.0f);
        vertices[2].position = Vector3(+0.5f, -0.5f, 0.0f);
        vertices[3].position = Vector3(-0.5f, +0.5f, 0.0f);
        break;
    case TextureRect::LEFT:
        vertices[0].position = Vector3(+0.0f, -0.5f, 0.0f);
        vertices[1].position = Vector3(+1.0f, +0.5f, 0.0f);
        vertices[2].position = Vector3(+1.0f, -0.5f, 0.0f);
        vertices[3].position = Vector3(+0.0f, +0.5f, 0.0f);
        break;
    case TextureRect::RIGHT:
        vertices[0].position = Vector3(-1.0f, -0.5f, 0.0f);
        vertices[1].position = Vector3(+0.0f, +0.5f, 0.0f);
        vertices[2].position = Vector3(+0.0f, -0.5f, 0.0f);
        vertices[3].position = Vector3(-1.0f, +0.5f, 0.0f);
        break;
    case TextureRect::UP:
        vertices[0].position = Vector3(-0.5f, -1.0f, 0.0f);
        vertices[1].position = Vector3(+0.5f, +0.0f, 0.0f);
        vertices[2].position = Vector3(+0.5f, -1.0f, 0.0f);
        vertices[3].position = Vector3(-0.5f, +0.0f, 0.0f);
        break;
    case TextureRect::DOWN:
        vertices[0].position = Vector3(-0.5f, +0.0f, 0.0f);
        vertices[1].position = Vector3(+0.5f, +1.0f, 0.0f);
        vertices[2].position = Vector3(+0.5f, +0.0f, 0.0f);
        vertices[3].position = Vector3(-0.5f, +1.0f, 0.0f);
        break;
    }

    vertices[0].uv = Vector2(0, 1);
    vertices[1].uv = Vector2(1, 0);
    vertices[2].uv = Vector2(1, 1);
    vertices[3].uv = Vector2(0, 0);
}
