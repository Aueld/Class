#include "stdafx.h"
#include "10_PlatDemo.h"

#include "Geometries/TextureCollRect.h"

void PlatDemo::Init()
{
    character = new TextureCollRect(
        Vector3(WinMaxWidth / 2, WinMaxHeight / 2, 0),
        Vector3(100, 100, 0), 0,
        TexturePath + L"images.jpg", CENTER, 250.0f
    );
    
    for (int i = 0; i < 6; i++)
    {
        plat.push_back(new TextureCollRect(
            Vector3(rand() % WinMaxWidth / 2, WinMaxHeight / 6 * i, 0),
            Vector3(100, 50, 0), 0,
            TexturePath + L"plat.png", CENTER, 150.0f
        ));
    }

    isGame = true;
}

void PlatDemo::Destroy()
{
    for(int i = 0; i < 6; i ++)
        SAFE_DELETE(plat[i]);
    SAFE_DELETE(character);
}

void PlatDemo::Update()
{
    if (isGame)
    {
        IsGameOver();

        character->Move();
        character->Update();
        character->Gravity();
        character->TotalScore();

        for (auto& p : plat)
        {
            p->Update();
            p->Gravity();

            if (p->GetPos().y < 0)
                p->ResetRandPos();

            p->OnBox(character);
        }
    }
}

void PlatDemo::Render()
{
    character->Render();

    for(auto& p : plat)
        p->Render();
}

void PlatDemo::PostRender()
{

}

void PlatDemo::GUI()
{
    character->GUI();
}

void PlatDemo::IsGameOver()
{
    if (character->GetPos().y < 0)
        isGame = false;
}
