#include "stdafx.h"
#include "MergeSort.h"

void DoMergeSort()
{
	vector<int> arr;

	for (int i = 0; i < 10; i++)
		arr.push_back(rand() % 100);

	for (int a : arr)
		cout << a << " ";

	cout << endll;

	MergeSort(arr, 0, arr.size() - 1);

	for (int a : arr)
		cout << a << " ";
}

void MergeSort(vector<int>& arr, int left, int right)
{
	// 리스트의 크기가 1 이하인 경우, 정렬이 이미 완료된 상태
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	// 왼쪽 부분 리스트를 재귀적으로 정렬
	MergeSort(arr, left, mid);
	// 오른쪽 부분 리스트를 재귀적으로 정렬
	MergeSort(arr, mid + 1, right);
	// 정렬된 왼쪽과 오른쪽 부분 리스트를 병합
	Merge(arr, left, mid, right);

}

void Merge(vector<int>& arr, int left, int mid, int right)
{
	int i = left; // 왼쪽 시작 인덱스
	int j = mid + 1; // 오른쪽 부분 리스트의 시작 인덱스
	int k = left; // 정렬된 결과를 저장할 배열의 인덱스
	vector<int> temp; // 병합 결과를 저장할 임시 배열
	temp.assign(arr.size(), int());

	// 왼쪽 부분 리스트와 오른쪽 부분 리스트의 요소들을 비교하여 임시 배열에 병합
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j]) // 내림차순 if (arr[i] >= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	// 왼쪽 부분 리스트나 오른쪽 부분 리스트의 요소 중 하나가 모두 병합된 경우,
	// 남은 요소들을 임시 배열에 추가
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];

	// 임시 배열에 저장된 병합 결과를 원래 배열에 복사
	for (int l = left; l <= right; l++)
		arr[l] = temp[l];
}
