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
    int pivot, leftKey, rightKey;

    if (left < right)
    {
        if (check)  // 오름차순
        {
            pivot = arr[left];  // 정렬할 벡터에 가장 왼쪽을 피벗으로 설정
            leftKey = left;
            rightKey = right + 1;

            while (true)
            {
                do
                {   // leftKey가 pivot보다 작으면 leftKey 증가
                    leftKey++;
                } while (leftKey <= right && arr[leftKey] < pivot);

                do
                {   // rightKey가 pivot보다 크면 rightKey 증가
                    rightKey--;
                } while (rightKey >= left && arr[rightKey] > pivot);

                // leftKey와 rightKey가 교차할때 탈출
                if (leftKey >= rightKey)
                    break;

                // leftKey와 rightKey가 교차하지 않았으므로 서로 스왑
                swap(arr[leftKey], arr[rightKey]);
            }
            // leftKey와 rightKey가 교차하여 반복문을 탈출했으므로 가장 왼쪽 값과 rightKey에 해당하는 값을 스왑
            swap(arr[left], arr[rightKey]);

            QuickSort(arr, left, rightKey - 1, check);  // left ~ 피벗 값 부분 정렬
            QuickSort(arr, rightKey + 1, right, check); // 피벗 값 ~ right 부분 정렬
        }
        else        // 내림차순
        {
            pivot = arr[right]; // 정렬할 벡터에 가장 오른쪽을 피벗으로 설정
            leftKey = left - 1;
            rightKey = right;

            while (true)
            {
                do
                {   // leftKey가 pivot보다 크면 leftKey 증가
                    leftKey++;
                } while (leftKey <= right && arr[leftKey] > pivot);
                do
                {   // rightKey가 pivot보다 작으면 rightKey 증가
                    rightKey--;
                } while (rightKey >= left && arr[rightKey] < pivot);

                // leftKey와 rightKey가 교차할때 탈출
                if (leftKey >= rightKey)
                    break;

                // leftKey와 rightKey가 교차하지 않았으므로 서로 스왑
                swap(arr[leftKey], arr[rightKey]);
            }
            // leftKey와 rightKey가 교차하여 반복문을 탈출했으므로 가장 leftKey값과 가장 오른쪽에 해당하는 값을 스왑
            swap(arr[leftKey], arr[right]);

            QuickSort(arr, left, leftKey - 1, check);   // left ~ 피벗 값 부분 정렬
            QuickSort(arr, leftKey + 1, right, check);  // 피벗 값 ~ right 부분 정렬
        }
    }
}
