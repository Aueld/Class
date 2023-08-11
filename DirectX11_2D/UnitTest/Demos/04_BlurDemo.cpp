#include "stdafx.h"
#include "04_BlurDemo.h"

#include "Geometries/BlurTexture.h"

void BlurDemo::Init()
{
	Vector3 pos = { WinMaxWidth / 2, WinMaxHeight / 2, 0 };
	Vector3 size = { 700, 700, 0 };
	bt = new BlurTexture(pos, size, 0, TexturePath + L"sadcat.jpg");
}

void BlurDemo::Destroy()
{
	SAFE_DELETE(bt);
}

void BlurDemo::Update()
{
	bt->Update();
}

void BlurDemo::Render()
{
	bt->Render();
}

void BlurDemo::PostRender()
{}

void BlurDemo::GUI()
{
	bt->GUI();
}
