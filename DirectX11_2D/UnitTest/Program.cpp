#include "stdafx.h"
#include "Program.h"

#include "Systems/Window.h"

#include "Demos/01_RectDemo.h"
#include "Demos/02_TextureDemo.h"
#include "Demos/03_ShadedDemo.h"
#include "Demos/04_RTVDemo.h"
#include "Demos/05_CollisionDemo.h"
#include "Demos/06_AnimationDemo.h"

#include "Demos/10_PlatDemo.h"

void Program::Init()
{
	Camera::Create();

	//{
	//	vpb = new VPBuffer();
	//	D3DXMatrixLookAtLH
	//	(
	//		&view,
	//		&Vector3(0, 0, 0),
	//		&Vector3(0, 0, 1),
	//		&Vector3(0, 1, 0)
	//	);
	//	D3DXMatrixOrthoOffCenterLH
	//	(
	//		&proj,
	//		0.0f,
	//		(float)WinMaxWidth,
	//		0.0f,
	//		(float)WinMaxHeight,
	//		0,
	//		1
	//	);
	//	vpb->SetView(view);
	//	vpb->SetProjection(proj);
	//}

	//Push(new RectDemo);
	//Push(new TextureDemo);
	//Push(new ShadedDemo);
	//Push(new RTVDemo);
	//Push(new CollisionDemo);
	//Push(new PlatDemo);
	Push(new AnimationDemo);
}

void Program::Destroy()
{
	Camera::Delete();
	//SAFE_DELETE(vpb);
	for (IObject* obj : objs)
	{
		obj->Destroy();
		SAFE_DELETE(obj);
	}
}

void Program::Update()
{
	for (IObject* obj : objs)
		obj->Update();

	Camera::Get()->Move();
}

void Program::Render()
{
	//vpb->SetVSBuffer(1);

	for (IObject* obj : objs)
		obj->Render();

	Camera::Get()->UpdateView();
	Camera::Get()->Render();
}

void Program::PostRender()
{
	for (IObject* obj : objs)
		obj->PostRender();
}

void Program::GUI()
{
	for (IObject* obj : objs)
	{
		obj->GUI();
	}
}

void Program::Push(IObject* obj)
{
	objs.push_back(obj);
	obj->Init();
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR param, int command)
{
	srand((UINT)time(NULL));

	DXDesc desc;
	desc.AppName = L"D2DGame";
	desc.instance = instance;
	desc.handle = NULL;
	desc.width = WinMaxWidth;
	desc.height = WinMaxHeight;

	Program* program = new Program();
	Window* window = new Window(desc);
	WPARAM wParam = window->Run(program);

	SAFE_DELETE(window);
	SAFE_DELETE(program);

	return wParam;

}
