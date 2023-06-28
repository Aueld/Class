/*
	STL
	- Standard Template Library

	컨테이너 (container)
	- sequence		// ex) vector, 선형으로 저장하는 연속된 컨테이너
	- associative	// ex) map, 일정한 규칙에 따라 저장하는 연관 컨테이너, 데이터 접근, 자동 정렬, 검색에 빠름, Key - value 형태
	- adapter		// ex) stack, 특정 형태의 데이터만 지원, iterater 사용 불가, 변형된 컨테이너

	반복자 (interator)
	// 컨테이너의 데이터를 접근하여 가르키는 것, 컨테이너의 포인터

	알고리즘 (algorithm)
	// 함수 템플릿
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

void Seqeunce_Container();
void Associative_Container();
void Adapter_Container();

int main()
{
	//Seqeunce_Container();
	//Associative_Container();
	Adapter_Container();

	return 0;
}

void Seqeunce_Container()	// 데이터를 선형으로 저장, 연속적인 데이터 관리
{
	// vector
	// 연속된 데이터, 중간에 데이터 삽입 삭제가 없는 경우
	{
		cout << "Vector" << endl;

		std::vector<int> vec;

		for (int i = 0; i < 10; i++)
		{
			vec.push_back(i);
		}

		// 임의 접근
		for (int i = 0; i < 10; i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;

		// 범위 기반
		for (const auto& ele : vec)
		{
			cout << ele << " ";
		}
		cout << endl << "iterator" << endl;

		// iterator, 반복자
		for (auto iter = vec.begin(); iter != vec.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}

	// Deque
	// 서로 떨어져 있는 공간에 데이터 저장, 크기 예측이 안될때
	{
		cout << "Deque" << endl;

		std::deque<int> deq;

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		// 범위 기반
		for (const auto& ele : deq)
		{
			cout << ele << " ";
		}
		cout << endl;
	}

	// List
	// 단방향, 양방향, 순차적인 접근, 인덱스 접근 불가,
	// 중간 삽입 삭제가 상대적으로 빨라 삽입 삭제가 빈번할때
	{
		cout << "List" << endl;
		
		std::list<int> list;
		
		for (int i = 0; i < 10; i++)
		{
			//list.push_back(i);
			list.push_front(i);
		}

		list.reverse();

		// 범위 기반
		for (const auto& ele : list)
		{
			cout << ele << " ";
		}
		cout << endl;
	}

	// 범위 기반으로 사용하는 이유는 일반화를 위해서, 다른 컨테이너여도 대응 할 수 있게 작용
}

void Associative_Container() // 일정한 규칙에 따라 데이터 저장, 자동 정렬
{
	// set
	// 자동 정렬, 중복 데이터 삽입 허용하지 않음
	{
		cout << "Set" << endl;

		std::set<string> strSet;

		strSet.insert("World");
		strSet.insert("Hello");
		strSet.insert("Hello");

		// 중복 데이터 삽입 허용하지 않음

		cout << strSet.size() << endl;

		for (auto& a : strSet)
		{
			cout << a << " ";
		}
		cout << endl;
	}
	
	// multiset
	// 자동 정렬, 중복 데이터 삽입 허용
	{
		cout << "MultiSet" << endl;

		multiset<string> strSet;

		strSet.insert("World");
		strSet.insert("Hello");
		strSet.insert("Hello");

		cout << strSet.size() << endl;

		for (auto& ele : strSet)
		{
			cout << ele << " ";
		}
		cout << endl;
	}

	// map
	// key, value 자동 정렬, 중복 데이터 삽입 허용하지 않음
	{
		cout << "Map" << endl;

		map<char, int> map;
	
		// 맵핑
		map.insert(pair<char, int>('d', 60));
		map['c'] = 50;
		map['a'] = 40;
		map['b'] = 30;

		cout << map['a'] << endl;

		// key값 기준으로 정렬
		for (const auto& ele : map)
		{
			cout << ele.first << ", " << ele.second << " ";
		}

		cout << endl;
	}

	// multimap
	// key, vlaue 자동 정렬, 중복 데이터 삽입 허용, 하나의 키에 여러 값 저장
	{
		cout << "MultiMap" << endl;

		std::multimap<char, int> multimap;

		// 맵핑
		// multimap은 insert(pair<>()) 구조로 삽입
		// pair은 구조체와 비슷, 두개만 저장 할 수 있는 구조체
		multimap.insert(pair<char, int>('a', 10));
		multimap.insert(pair<char, int>('b', 20));
		multimap.insert(make_pair('a', 50));	// 컴파일러가 자동으로 판단

		// 몇개 저장 되었는지 확인
		cout << multimap.count('a') << endl;

		// key값 기준으로 정렬
		for (const auto& ele : multimap)
		{
			cout << ele.first << ", " << ele.second << " ";
		}

		cout << endl;
	}
}

void Adapter_Container() // 기존 컨테이너를 변형하여 만든 컨테이너, 인덱스 접근 불가
{
	// stack
	// - LIFO(Last In First Out)
	// vector 변형
	{
		cout << "Stack" << endl;

		std::stack<int> stack;
		stack.push(4);		//push adds a copy, 복사
		stack.emplace(1);	//emplace constructs a new object, 생성

		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
	}

	// queue
	// - FIFO(First In First Out)
	// deque 변형
	{
		cout << "Queue" << endl;

		std::queue<int> queue;
		queue.push(5);
		queue.emplace(3);
		queue.push(2);
		queue.push(6);

		cout << queue.front() << ", " << queue.back() << endl;

		queue.pop();
		
		cout << queue.front() << ", " << queue.back() << endl;
	}

	// priority Queue
	// - FIFO(First In First Out)
	// 우선순위 큐, 정렬(가장 큰 숫자가 앞, 내림차순)
	// vector 변형
	{
		cout << "Priority Queue" << endl;
		priority_queue<int> pq;
		
		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
		{
			pq.push(n);
		}

		for (int i = 0; i < 10; i++)
		{
			cout << pq.top() << ", ";
			pq.pop();
		}
		cout << endl;
	}
}
