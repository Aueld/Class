#include "stdafx.h"
#include "QuickSort.h"

void DoQuickSort()
{
    srand(time(NULL));

    vector<int> arr;

    for (int i = 0; i < 10; i++)
        arr.push_back(rand() % 100);

    for (int a : arr)
        cout << a << " ";

    cout << endll;
    cout << "오름차순" << endl;

    QuickSort(arr, 0, arr.size() - 1, true);

    for (int a : arr)
        cout << a << " ";

    cout << endll;
    cout << "내림차순" << endl;

    QuickSort(arr, 0, arr.size() - 1, false);

    for (int a : arr)
        cout << a << " ";
}

void QuickSort(vector<int>& arr, int left, int right, bool check)
{
    // 리스트의 크기가 1 이하인 경우, 정렬이 이미 완료된 상태
    if (left >= right)
        return;

    // 리스트의 첫 요소를 pivot으로 설정
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    // i와 j가 교차 할 때까지 pivot보다 작은 요소는 i를,
    // pivot보다 큰 요소는 j를 찾음.
    while (i <= j)
    {
        if (check)
        {
            while (i <= right && arr[i] <= pivot)
                i++;
            while (j >= left + 1 && arr[j] >= pivot)
                j--;
        }
        else
        {
            while (i <= right && arr[i] > pivot)
                i++;
            while (j >= left + 1 && arr[j] < pivot)
                j--;
        }

        // i와 j가 교차하지 않은 경우, i와 j의 요소를 swap
        if (i <= j)
            swap(arr[i], arr[j]);
    }
    // pivot을 기준으로 분할된 왼쪽과 오른쪽 부분 리스트를 재귀적으로 정렬
    swap(arr[left], arr[j]);

    QuickSort(arr, left, j - 1, check);
    QuickSort(arr, i + 1, right, check);
}
