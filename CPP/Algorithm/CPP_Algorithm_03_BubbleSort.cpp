#include "stdafx.h"
#include "BubbleSort.h"

void DoBubbleSort()
{
	vector<int> arr;

	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int a : arr)
		cout << a << " ";

	cout << endll;

	BubbleSort(arr);

	for (int a : arr)
		cout << a << " ";
}

void BubbleSort(vector<int>&arr)
{
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}
