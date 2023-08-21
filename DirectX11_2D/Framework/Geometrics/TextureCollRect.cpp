#include "Framework.h"
#include "TextureCollRect.h"

TextureCollRect::TextureCollRect(Vector3 position, Vector3 size, float rotation, wstring path, Pivot pivot, float velo)
    : position(position), size(size), rotation(rotation), pivot(pivot), velocityY(velo)
{
    this->pivot = CENTER;

    SetVertices();

    vb = new VertexBuffer();
    vb->Create(vertices, D3D11_USAGE_DYNAMIC);

    indices = { 0,1,2,0,3,1 };
    ib = new IndexBuffer;
    ib->Create(indices, D3D11_USAGE_IMMUTABLE);

    vs = new VertexShader;
    vs->Create(ShaderPath + L"VertexTexture.hlsl", "VS");

    ps = new PixelShader;
    ps->Create(ShaderPath + L"VertexTexture.hlsl", "PS");

    il = new InputLayout;
    il->Create(VertexTexture::descs, VertexTexture::count, vs->GetBlob());

    wb = new WorldBuffer;

    HRESULT hr = D3DX11CreateShaderResourceViewFromFile
    (
        DEVICE,
        path.c_str(),
        nullptr,
        nullptr,
        &srv,
        nullptr
    );
    CHECK(hr);

    box = new BoundingBox(position, { size.x, size.y / 4 * 3, size.z }, rotation, Color(1, 0, 0, 0.3f), UP);
    plat = new BoundingBox(position, { size.x, size.y / 4, size.z }, rotation, Color(0, 1, 0, 0.3f), DOWN);
}

TextureCollRect::TextureCollRect(Vector3 position, Vector3 size, float rotation)
    : position(position), size(size), rotation(rotation)
{
    SetVertices();

    vb = new VertexBuffer();
    vb->Create(vertices, D3D11_USAGE_DYNAMIC);

    indices = { 0,1,2,0,3,1 };
    ib = new IndexBuffer;
    ib->Create(indices, D3D11_USAGE_IMMUTABLE);

    vs = new VertexShader;
    vs->Create(ShaderPath + L"VertexTexture.hlsl", "VS");

    ps = new PixelShader;
    ps->Create(ShaderPath + L"VertexTexture.hlsl", "PS");

    il = new InputLayout;
    il->Create(VertexTexture::descs, VertexTexture::count, vs->GetBlob());

    wb = new WorldBuffer;

    box = new BoundingBox(position, size, rotation, Color(1, 0, 0, 1), UP);
    plat = new BoundingBox(position, size, rotation, Color(0, 1, 0, 1), DOWN);
}

TextureCollRect::~TextureCollRect()
{
    SAFE_DELETE(plat);
    SAFE_DELETE(box);
    SAFE_DELETE(wb);
    SAFE_DELETE(il);
    SAFE_DELETE(ps);
    SAFE_DELETE(vs);
    SAFE_DELETE(ib);
    SAFE_DELETE(vb);
}

void TextureCollRect::Update()
{
    UpdateWorld();

    box->Update({ position.x, position.y + size.y / 8, position.z }, { size.x, size.y / 4 * 3, size.z }, rotation, UP);
    plat->Update({ position.x, position.y - size.y / 8 * 3, position.z }, { size.x, size.y / 4, size.z }, rotation, DOWN);
}

void TextureCollRect::UpdateWorld()
{
    D3DXMatrixScaling(&S, size.x, size.y, size.z);
    D3DXMatrixRotationZ(&R, rotation);
    D3DXMatrixTranslation(&T, position.x, position.y, position.z);

    world = S * R * T;
    wb->SetWorld(world);
}

void TextureCollRect::Render()
{
    vb->SetIA();
    ib->SetIA();
    il->SetIA();
    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    vs->SetShader();
    ps->SetShader();
    wb->SetVSBuffer(0);

    DC->PSSetShaderResources(0, 1, &srv);

    DC->DrawIndexed(ib->GetCount(), 0, 0);

    box->Render();
    plat->Render();
}

void TextureCollRect::GUI()
{
    using namespace ImGui;
    Begin("Jump");
    {
        Text("Score      : %3.0f", score);
        Text("Jump Count : %3d", 2 - jumpCount);
    }
    End();
}

void TextureCollRect::SetShader(wstring shaderPath)
{
    vs->Clear();
    ps->Clear();
    vs->Create(ShaderPath + shaderPath, "VS");
    ps->Create(ShaderPath + shaderPath, "PS");
}

void TextureCollRect::Gravity()
{
    float delta = Time::Delta();

    position.y -= velocityY * delta;
}

void TextureCollRect::Jump()
{
    if (GetJumpCount() > 2)
        return;

    float delta = Time::Delta();
    position.y += 800 * delta;
}

void TextureCollRect::Move()
{
    auto key = Keyboard::Get();
    float delta = Time::Delta();

    if (key->Down('W'))
        JumpCountPlus();

    if (key->Press('W'))
        Jump();

    if (key->Press('S'))
        position.y -= 300 * delta;
    if (key->Press('A'))
        position.x -= 300 * delta;
    if (key->Press('D'))
        position.x += 300 * delta;
}

void TextureCollRect::OnBox(TextureCollRect* ch)
{
    float time = Time::Delta();

    if (BoundingBox::AABB(ch->GetPlat(), this->GetBox()))
    {
        ch->ResetJumpCount();
        
        if (ch->GetPos().y <= this->position.y + 80)
            ch->position.y += 200 * time;
        else
            ch->position.y += 100 * time;
    }
}

void TextureCollRect::ResetRandPos()
{
    position.x = rand() % WinMaxWidth;
    position.y = 720;
}

void TextureCollRect::TotalScore()
{
    float time = Time::Delta();

    score += time;
}

void TextureCollRect::SetVertices()
{
    vertices.assign(4, VertexTexture());

    switch (pivot)
    {
    case CENTER:
        vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
        vertices[1].position = Vector3(+0.5f, +0.5f, 0.0f);
        vertices[2].position = Vector3(+0.5f, -0.5f, 0.0f);
        vertices[3].position = Vector3(-0.5f, +0.5f, 0.0f);
        break;
    case LEFT:
        vertices[0].position = Vector3(-0.0f, -0.5f, 0.0f);
        vertices[1].position = Vector3(+1.0f, +0.5f, 0.0f);
        vertices[2].position = Vector3(+1.0f, -0.5f, 0.0f);
        vertices[3].position = Vector3(-0.0f, +0.5f, 0.0f);
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
        vertices[0].position = Vector3(-0.5f, -0.0f, 0.0f);
        vertices[1].position = Vector3(+0.5f, +1.0f, 0.0f);
        vertices[2].position = Vector3(+0.5f, -0.0f, 0.0f);
        vertices[3].position = Vector3(-0.5f, +1.0f, 0.0f);
        break;
    }

    vertices[0].uv = Vector2(0, 1);
    vertices[1].uv = Vector2(1, 0);
    vertices[2].uv = Vector2(1, 1);
    vertices[3].uv = Vector2(0, 0);
}
