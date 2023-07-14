#include "stdafx.h"
#include "Queue.h"

template<typename T>
inline void Queue<T>::Enqueue(T data)
{
    if (IsFull())
    {
        cout << "Queue is FULL" << endl;
        return;
    }

    Data[Rear] = data;
    Rear = (Rear + 1) % MAX_SIZE;
    Size++;
}

template<typename T>
inline void Queue<T>::Dequeue()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    Front = (Front + 1) % MAX_SIZE;
    Size--;
}

template<typename T>
inline T Queue<T>::GetFront()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty" << endl;
        return T();
    }

    return Data[Front];
}

