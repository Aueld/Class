/*
	입력할 단어 개수 m
	게임을 진행할 횟수 n

	단어 개수 m에 맞게 단어 입력
	n의 횟수에 따라 출력

	단어를 입력하면 숫자가 출력
	숫자를 입력하면 단어가 출력

	// stoi(str) 사용
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<int, string> container;

	string m = "", n = "";
	string word = "", input = "";

	bool check = false;
	
	while (true)
	{
		cout << "입력할 단어 개수 입력 : ";
		cin >> m;

		if (atoi(m.c_str()) != 0 || m.compare("0") == 0)
			break;
	}
	while (true)
	{
		cout << "게임을 진행 할 횟수 입력 : ";
		cin >> n;

		if (atoi(n.c_str()) != 0 || n.compare("0") == 0)
			break;
	}

	for (int i = 0; i < stoi(m); i++)
	{
		cout << i + 1 << "번째 단어 입력" << endl;
		cin >> word;

		if (atoi(word.c_str()) != 0 || word.compare("0") == 0)
		{
			cout << "숫자를 입력 할 수 없습니다." << endl;
			i--;
			continue;
		}
		
		container.insert(make_pair(i, word));
	}

	for (int i = 0; i < stoi(n); i++)
	{
		cout << i + 1 << "번째 게임 진행" << endl;
		cin >> input;
		
		if (atoi(input.c_str()) != 0 || input.compare("0") == 0)
		{
			for (auto iter = container.begin(); iter != container.end(); iter++)
			{
				if (iter->first == stoi(input) - 1)
				{
					cout << stoi(input) << "번째 단어 : " << iter->second << endl;
					check = true;
				}
			}
		}
		else
		{
			for (auto iter = container.begin(); iter != container.end(); iter++)
			{
				if (iter->second == input)
				{
					cout << input << "의 번호 : " << iter->first + 1 << endl;
					check = true;
				}
			}
		}

		if (!check)
		{
			cout << "잘못된 입력입니다." << endl;
			i--;
		}

		check = false;
	}

	return 0;
}
