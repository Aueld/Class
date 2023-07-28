#pragma once

class VertexBuffer
{
public:

	~VertexBuffer();

	template<typename T>
	void Create(const vector<T>& vertices, const D3D11_USAGE& usage = D3D11_USAGE);

	ID3D11Buffer* GetResource() { return buffer; }

	uint GetStride() { return stride; }
	uint GetOffset() { return offset; }
	uint GetCount() { return count; }

	void SetIA();

private:
	ID3D11Buffer* buffer = nullptr;

	uint stride = 0;		// 정점 크기
	uint offset = 0;		// 정점 오프셋
	uint count = 0;			// 정점 개수
};

template<typename T>
inline void VertexBuffer::Create(const vector<T>& vertices, const D3D11_USAGE& usage)
{
	stride = sizeof(T);
	count = vertices.size();

	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

	desc.Usage = usage;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	desc.ByteWidth = stride * count;

	// CPU 액세스 플래그 설정
	switch (usage)
	{
	case D3D11_USAGE_DEFAULT:
	case D3D11_USAGE_IMMUTABLE:
		break;

	case D3D_USAGE_DYNAMIC:
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		break;

	case D3D11_USAGE_STAGING:
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
		break;
	}

}
