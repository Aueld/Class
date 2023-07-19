#include "stdafx.h"
#include "SelectionSort.h"

void DoSelectionSort()
{
	vector<int> arr;

	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int a : arr)
		cout << a << " ";

	cout << endll;

	SelectionSort(arr);

	for (int a : arr)
		cout << a << " ";
}

void Swap(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void SelectionSort(vector<int>& arr)
{
	int index;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] < arr[index])
				index = j;

		Swap(arr[index], arr[i]);
	}
}
