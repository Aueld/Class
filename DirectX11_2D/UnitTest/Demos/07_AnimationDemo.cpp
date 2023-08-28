#include "stdafx.h"
#include "07_AnimationDemo.h"

#include "Geometries/AnimationRect.h"
#include "Geometries/Player.h"

void AnimationDemo::Init()
{
	//ar = new AnimationRect({ 720, 360, 0 }, { 200, 200, 0 });
	player = new Player({ 720, 360, 0 }, { 200, 200, 0 });
}

void AnimationDemo::Destroy()
{
	//SAFE_DELETE(ar);
	SAFE_DELETE(player);
}

void AnimationDemo::Update()
{
	//ar->Update();
	player->Update();
}

void AnimationDemo::Render()
{
	//ar->Render();
	player->Render();
}

void AnimationDemo::PostRender()
{}

void AnimationDemo::GUI()
{}
