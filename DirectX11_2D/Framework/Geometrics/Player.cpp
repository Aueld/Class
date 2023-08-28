#include "Framework.h"
#include "Player.h"

Player::Player(Vector3 position, Vector3 size)
{
    animRect = new AnimationRect(position, size);
    animator = new Animator();

    // 좌표 왼쪽 상단 0, 0
    // 좌표 오른쪽 하단 GetWidth, GetHeight
    // Vector2(시작 왼쪽 상단 좌표), Vector2(끝 오른쪽 하단 좌표)
    Texture2D* srcTex = new Texture2D(CharacterPath + L"jelda.png");
    Vector2 texSize = Vector2(srcTex->GetWidth(), srcTex->GetHeight());
    
    AnimationClip* Run_Up = new AnimationClip
    (
        L"Run_Up", srcTex, 10,
        Vector2(0.0f, texSize.y * 0.5f),
        Vector2(texSize.x, texSize.y * 0.75f),
        1.0f / 15.0f, true
    );
    AnimationClip* Run_Down = new AnimationClip
    (
        L"Run_Down", srcTex, 10,
        Vector2(0.0f, 0.0f),
        Vector2(texSize.x, texSize.y * 0.25f),
        1.0f / 15.0f
    );
    AnimationClip* Run_Left = new AnimationClip
    (
        L"Run_Left", srcTex, 10,
        Vector2(0.0f, texSize.y * 0.25f),
        Vector2(texSize.x, texSize.y * 0.5f),
        1.0f / 15.0f, true
    );
    AnimationClip* Run_Right = new AnimationClip
    (
        L"Run_Right", srcTex, 10,
        Vector2(0.0f, texSize.y * 0.75f),
        Vector2(texSize.x, texSize.y),
        1.0f / 15.0f
    );

    animator->AddAnimClip(Run_Up);
    animator->AddAnimClip(Run_Down);
    animator->AddAnimClip(Run_Left);
    animator->AddAnimClip(Run_Right);
    animator->SetCurrentAnimClip(L"Run_Down");

    animRect->SetAnimation(animator);

    SAFE_DELETE(srcTex);
}

Player::~Player()
{
	SAFE_DELETE(animator);
	SAFE_DELETE(animRect);
}

void Player::Update()
{
    animator->Update();
    Move();
    animRect->Update();
}

void Player::Render()
{
    animRect->Render();
}

void Player::Move()
{
    auto* keyboard = Keyboard::Get();
    float delta = Time::Delta();
    Vector3 pos = animRect->GetPosition();

    if (keyboard->Press('W') && keyboard->Press('D'))
    {
        animRect->SetPosition(pos + Vector3(200 * delta, 200 * delta, 0));
        animator->SetCurrentAnimClip(L"Run_Up");
    }
    else if (keyboard->Press('W') && keyboard->Press('A'))
    {
        animRect->SetPosition(pos + Vector3(-200 * delta, 200 * delta, 0));
        animator->SetCurrentAnimClip(L"Run_Up");
    }
    else if (keyboard->Press('S') && keyboard->Press('D'))
    {
        animRect->SetPosition(pos + Vector3(200 * delta, -200 * delta, 0));
        animator->SetCurrentAnimClip(L"Run_Down");
    }
    else if (keyboard->Press('S') && keyboard->Press('A'))
    {
        animRect->SetPosition(pos + Vector3(-200 * delta, -200 * delta, 0));
        animator->SetCurrentAnimClip(L"Run_Down");
    }
    else if (keyboard->Press('W'))
    {
        animRect->SetPosition(pos + Vector3(0, 200 * delta, 0));
        animator->SetCurrentAnimClip(L"Run_Up");
    }
    else if (keyboard->Press('S'))
    {
        animRect->SetPosition(pos + Vector3(0, -200 * delta, 0));
        animator->SetCurrentAnimClip(L"Run_Down");
    }
    else if (keyboard->Press('A'))
    {
        animRect->SetPosition(pos + Vector3(-200 * delta, 0, 0));
        animator->SetCurrentAnimClip(L"Run_Left");
    }
    else if (keyboard->Press('D'))
    {
        animRect->SetPosition(pos + Vector3(200 * delta, 0, 0));
        animator->SetCurrentAnimClip(L"Run_Right");
    }
}
