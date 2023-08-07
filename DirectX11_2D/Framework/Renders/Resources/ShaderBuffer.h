#pragma once
#include "Framework.h"

class ShaderBuffer
{
public:
	void SetVSBuffer(uint slot)
	{
		MapData();
		DC->VSSetConstantBuffers(slot, 1, &buffer);
	}

	void SetPSBuffer(uint slot)
	{
		MapData();
		DC->PSSetConstantBuffers(slot, 1, &buffer);
	}

protected:
	ShaderBuffer(void* data, uint dataSize)
		: data(data), dataSize(dataSize)
	{
		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.ByteWidth = dataSize;
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;	// 값을 바꿔주는 버퍼
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		HRESULT hr = DEVICE->CreateBuffer(&desc, nullptr, &buffer);
		CHECK(hr);
	}

private:
	void MapData() // 맵, 언맵
	{
		// 데이터가 담긴 곳에 접근하여 열고 데이터를 꺼내고 닫는 과정
		D3D11_MAPPED_SUBRESOURCE subResource;
		HRESULT hr = DC->Map
		(
			buffer,		// 무엇을
			0,			// 어디서부터
			D3D11_MAP_WRITE_DISCARD,
			0,
			&subResource // 복사 할 것
		);
		CHECK(hr);

		memcpy(subResource.pData, data, dataSize);
		DC->Unmap(buffer, 0);
	}

private:
	D3D11_BUFFER_DESC desc = { 0 };
	ID3D11Buffer* buffer = nullptr;

	void* data = nullptr;
	uint dataSize = 0;
};
