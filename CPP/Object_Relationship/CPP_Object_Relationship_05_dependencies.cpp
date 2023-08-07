#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer
{
public:
	Timer()
	{
		start_time = high_resolution_clock::now();
	}

	void Elapsed()
	{
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli> delta = current_time - start_time;

		// delta 값 출력
		cout << delta.count();
	}

private:
	// 타임 마크<가장 최적화 시간>
	time_point<high_resolution_clock> start_time;
};

class Worker
{
public:
	void DoSometing()
	{
		Timer timer;
		for (int i = 0; i < 100'000'000; i++);

		timer.Elapsed();
		// timer는 Worker에서 잠깐만 쓰인 의존 관계
	}
};

int main()
{
	Worker worker;
	worker.DoSometing();

	return 0;
}
