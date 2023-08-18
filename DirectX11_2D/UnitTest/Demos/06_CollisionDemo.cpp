#include "stdafx.h"
#include "06_CollisionDemo.h"

#include "Geometries/Rect.h"

void CollisionDemo::Init()
{
	r1 = new Rect({ 200,200,0 }, { 100,100,0 }, 45);
	r2 = new Rect({ 500,400,0 }, { 100,100,0 }, 0);
}

void CollisionDemo::Destroy()
{
	SAFE_DELETE(r2);
	SAFE_DELETE(r1);
}

void CollisionDemo::Update()
{
	r1->Move();

	r1->Update();
	r2->Update();

	//if (BoundingBox::AABB(r1->GetBox(), r2->GetBox()))
	if (BoundingBox::OBB(r1->GetBox(), r2->GetBox()))
		r2->SetColor(Values::Green);
	else
		r2->SetColor(Values::Red);
}

void CollisionDemo::Render()
{
	r1->Render();
	r2->Render();
}

void CollisionDemo::PostRender()
{

}

void CollisionDemo::GUI()
{

}
