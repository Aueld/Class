#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
	// vector
	{
		cout << "Vector Iterator" << endl;

		vector<int> container;
		for (int i = 0; i < 10; i++)
		{
			container.push_back(i);
		}

		std::vector<int>::iterator iter;
		iter = container.begin();
		
		while (iter != container.end())
		{
			cout << *iter << " ";
			++iter;	// 포인터 연산
		}
		cout << endl;
	}

	// list
	{
		cout << "List Iterator" << endl;

		list<int> container;
		for (int i = 0; i < 10; i++)
		{
			container.push_back(i);
		}

		//std::list<int>::iterator iter;
		//iter = container.begin();

		// auto 는 매개변수로 사용 될 수 없음(22버전 미만일때)
		for (auto iter = container.begin(); iter != container.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}

	// map
	{
		cout << "Map Iterator" << endl;

		map<int, char> container;
		for (int i = 0; i < 10; i++)
		{
			container.insert(make_pair(i, i + 32));
		}

		for (auto iter = container.begin(); iter != container.end(); iter++)
		{
			cout << iter->first << ", " << iter->second << endl;
		}
		cout << endl;

		int answer;

		for (auto iter = container.begin(); iter != container.end(); iter++)
		{
			cin >> answer;

			if (container.find(answer) != container.end())
				cout << container.find(answer)->first << ", " << container.find(answer)->second << endl;
		}
		cout << endl;
	}

	return 0;
}
