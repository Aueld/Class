#include "Framework.h"
#include "VertexType.h"

D3D11_INPUT_ELEMENT_DESC VertexColor::descs[]
{
	{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
	{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0}
};

/*
* D3D11_INPUT_ELEMENT_DESC
	LPCSTR SemanticName;						: 정점 데이터의 의미를 나타내는 문구
	UINT SemanticIndex;							: 위 이름이 중복되는 경우 구분하기 위한 인덱스 값
	DXGI_FORMAT Format;							: 데이터의 형식
	UINT InputSlot;								: 입력 슬롯의 인덱스
	UINT AlignedByteOffset;						: 정점 데이터의 바이트 단위 오프셋
	D3D11_INPUT_CLASSIFICATION InputSlotClass;	: 사용되는 데이터 형식
	UINT InstanceDataStepRate;					: 인스턴스마다 데이터를 읽어 들이는데 사용할 스텝 레이트 값
*/												
