#include "stdafx.h"
#include "Stack.h"

template<typename T>
inline Stack<T>::Stack()
{
	Top = -1;
}

template<typename T>
inline void Stack<T>::Push(T data)
{
	if (IsFull())
	{
		cout << "Stack is Full" << endl;
		return;
	}

	Data[++Top] = data;
	return;
}

template<typename T>
inline T Stack<T>::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is NULL" << endl;
		return T();
	}

	return Data[Top--];
}

template<typename T>
inline T Stack<T>::Peek()
{
	if (IsEmpty())
	{
		cout << "Stack is NULL" << endl;
		return T();
	}

	return Data[Top];
}
