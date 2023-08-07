#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

random_device rd;
mt19937_64 mt(rd());

int main()
{
	vector<int> container;

	for (int i = 0; i < 10; i++)
	{
		container.push_back(i);
	}

	// algorithm
	// (시작, 끝, 시드값)
	shuffle(container.begin(), container.end(), mt);

	for (auto iter = container.begin(); iter != container.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	// 최솟값
	auto iter = min_element(container.begin(), container.end());
	cout << "최솟값" << *iter << endl;

	// 최댓값
	iter = max_element(container.begin(), container.end());
	cout << *iter << endl;

	// 찾기 (시작, 끝, 찾는 값)
	iter = find(container.begin(), container.end(), 7);
	cout << *iter << endl;

	// 정렬
	sort(container.begin(), container.end());
	for (auto iter = container.begin(); iter != container.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
