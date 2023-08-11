#include "stdafx.h"
#include "03_ShadedDemo.h"

#include "Geometries/ShadedTexture.h"

void ShadedDemo::Init()
{
	Vector3 pos = { WinMaxWidth / 2, WinMaxHeight / 2, 0 };
	Vector3 size = { 700, 700, 0 };
	st = new ShadedTexture(pos, size, 0,
		TexturePath + L"sadcat.jpg");
}

void ShadedDemo::Destroy()
{
	SAFE_DELETE(st);
}

void ShadedDemo::Update()
{
	st->Update();
}

void ShadedDemo::Render()
{
	st->Render();
}

void ShadedDemo::PostRender()
{

}

void ShadedDemo::GUI()
{
	st->GUI();
}
