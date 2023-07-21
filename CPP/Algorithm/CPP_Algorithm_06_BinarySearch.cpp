#include "stdafx.h"
#include "BinarySearch.h"

void DoBinarySearch()
{
	vector<int> arr;

	for (int i = 0; i < 20; i++)
		arr.push_back(i * 2);

	for (int a : arr)
		cout << a << " ";
	
	cout << endll;

	cout << BinarySearch(arr, 8) << "번째 인덱스" << endl;

	for (int a : arr)
		cout << a << " ";
}

int BinarySearch(vector<int>& arr, int find)
{
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == find)
			return mid;
		else if (arr[mid] < find)
			left = mid + 1;
		else if (arr[mid] > find)
			right = mid - 1;
		else
			return -1;
	}
}
