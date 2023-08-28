#include "Framework.h"
#include "AnimationRect.h"

AnimationRect::AnimationRect(Vector3 position, Vector3 size)
    : TextureRect(position, size, 0.0f)
{
    // 추 후 작업시 hlsl 파일 새로 만들어 사용 할 것
    //SetShader(ShaderPath + L"Animation.hlsl");

    // Sampler
    {
        D3D11_SAMPLER_DESC desc;
        // 선형 샘플링
        States::GetSamplerDesc(&desc);
        States::CreateSampler(&desc, &point[0]);

        // 점형 샘플링
        desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
        States::CreateSampler(&desc, &point[1]);
    }

    // Blend
    {
        D3D11_BLEND_DESC desc;
        States::GetBlendDesc(&desc);
        States::CreateBlend(&desc, &bPoint[0]);

        desc.RenderTarget[0].BlendEnable = true;
        States::CreateBlend(&desc, &bPoint[1]);
    }
}

AnimationRect::~AnimationRect()
{}

void AnimationRect::Update()
{
    animator->Update();

    MapVertexBuffer();
    {
        Vector2 frame = animator->GetCurrentFrame();
        Vector2 texelSize = animator->GetTexelFrameSize();
        vertices[0].uv.x = frame.x;
        vertices[0].uv.y = frame.y + texelSize.y;

        vertices[1].uv.x = frame.x + texelSize.x;
        vertices[1].uv.y = frame.y;

        vertices[2].uv.x = frame.x + texelSize.x;
        vertices[2].uv.y = frame.y + texelSize.y;

        vertices[3].uv.x = frame.x;
        vertices[3].uv.y = frame.y;
    }
    UnmapVertexBuffer();

    __super::Update();
}

void AnimationRect::Render()
{
    srv = animator->GetCurrentSRV();

    // 샘플링 및 블렌딩
    DC->PSSetSamplers(0, 1, &point[1]);
    DC->OMSetBlendState(bPoint[1], nullptr, (UINT)0xFFFFFFFF);

    __super::Render();
}

void AnimationRect::Move()
{
    //auto* keyboard = Keyboard::Get();
    //float delta = Time::Delta();

    //if (keyboard->Press('W'))
    //{
    //    position.y += 100 * delta;
    //}
    //if (keyboard->Press('S'))
    //{
    //    position.y -= 100 * delta;

    //}
    //if (keyboard->Press('A'))
    //{
    //    position.x -= 100 * delta;
    //    animator->SetCurrentAnimClip(L"Run_L");
    //}
    //if (keyboard->Press('D'))
    //{
    //    position.x += 100 * delta;
    //    animator->SetCurrentAnimClip(L"Run_R");
    //}
}
