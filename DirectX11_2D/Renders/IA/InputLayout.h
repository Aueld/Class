#pragma once

class InputLayout
{
public:
	~InputLayout();

	void Create(D3D11_INPUT_ELEMENT_DESC* descs, uint count, ID3DBlob* blob);

	void SetIA();

private:
	ID3D11InputLayout* inputLayout = nullptr;

};

/*
* InputLayout
	정점 버퍼의 데이터 구조를 정의
	정점 데이터의 각 요소의 형식, 크기, 순서등을 지정
	IA 단계에서 정점 셰이더로 데이터를 전달하기 전에 정점 데이터를 올바르게 해석하는데 사용

	단어 한 줄 정리 해볼 것
*/
