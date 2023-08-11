#pragma once

#include "TextureRect.h"

// CPU와 GPU의 통신을 위해 버퍼 선언
class ShadedBuffer : public ShaderBuffer
{
public:
	ShadedBuffer() : ShaderBuffer(&data, sizeof(Data))
	{
		data.Selection = 1;
	}

	int* GetSelectionPtr() { return &data.Selection; }

	struct Data
	{
		int Selection;
		Vector3 dummy;
	};

private:
	Data data;
};

class ShadedTexture : public TextureRect
{
public:
	ShadedTexture(Vector3 position, Vector3 size, float rotation, wstring path);
	~ShadedTexture();

	void Render();
	void GUI();

private:
	ShadedBuffer* sb = nullptr;
};

