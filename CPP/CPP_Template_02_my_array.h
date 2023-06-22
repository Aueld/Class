#pragma once

// 클래스 탬플릿
template<class T>
class my_array
{
public:
	my_array(int length);
	~my_array();

	void Print();

private:
	T* arr = nullptr;
	int length = 0;
};

// 함수 형식으로 쓰는 함수 내용의 코드

// 클래스 탬플릿 세가지 방법 존재
// 1. 클래스 탬플릿은 헤더에서 선언과 정의
template<class T>
inline my_array<T>::my_array(int length)
	: length(length)
{
	arr = new T[length];
}

template<class T>
inline my_array<T>::~my_array()
{
	if (arr != nullptr)
		delete[] arr;
}

//template<class T>
//inline void my_array<T>::Print()
//{}
