#pragma once

template<typename T>
class Stack
{
public:
	Stack();

	bool IsEmpty() { return Top == -1; }
	bool IsFull() { return Top == MAX_SIZE; }

	void Push(T data);

	T Pop();
	T Peek();

private:
	int Top;
	T Data[MAX_SIZE];
};

/*
	Stack : 스택
	- 특징
		1) 후입선출(LIFO) 구조
		2) 삽입은 push, 삭제는 pop
	- 장점
		1) 구현이 간단
		2) 함수 호출의 역추적, 수식 계산, 문자역 역순 등에 유용
	- 단점
		1) 중간의 원소에 접근하기 어려움
*/
