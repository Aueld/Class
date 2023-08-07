#pragma once

#include "IShader.h"

class VertexShader : public IShader
{
public:
	~VertexShader();

	virtual void Create(const wstring path, const string entryName) override;
	virtual void Clear() override;
	virtual void SetShader() override;

private:
	ID3D11VertexShader* shader = nullptr;
	ID3DBlob* blob = nullptr;
};

