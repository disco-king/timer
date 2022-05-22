#pragma once

#include <sys/time.h>
#include <chrono>
#include <iostream>

#define USECS 1
#define MSECS 2

class Timer
{

public:
	typedef std::chrono::system_clock clock;
	typedef std::chrono::microseconds usecs;
	typedef std::chrono::milliseconds msecs;
	typedef std::chrono::time_point<clock> point;
	typedef std::chrono::duration<double, std::micro> duration;

private:
	point start_point;
	point finish_point;
	duration time;

public:

	void start();
	void finish();
	duration getTime(int unit);
	void printTime(int unit);

	Timer() : start_point(clock::now()),
				finish_point(clock::now())
	{};

};

void Timer::start()
{
	start_point = clock::now();
}

void Timer::finish()
{
	finish_point = clock::now();
	time = finish_point - start_point;
}

Timer::duration Timer::getTime(int unit)
{
	return time;
}

void Timer::printTime(int unit)
{
	std::cout << "time elapsed: " 
	<< std::fixed
	<< time.count() << '\n';
}