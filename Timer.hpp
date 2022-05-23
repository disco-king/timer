#pragma once

#include <sys/time.h>
#include <chrono>
#include <iostream>

#define MICRO std::micro
#define MILLI std::milli
#define CENTI std::centi
#define DECI std::deci
#define DECA std::deca


template <typename Data = double, typename Unit = std::micro>
class Timer
{

public:
	typedef std::milli milli;
	typedef std::micro micro;
	typedef std::chrono::system_clock clock;
	typedef std::chrono::time_point<clock> point;
	typedef std::chrono::duration<Data, Unit> duration;

private:
	point start_point;
	point finish_point;
	duration time;

public:

	void start();
	void finish();
	duration getTime();
	void printTime();

	Timer() : start_point(),
				finish_point()
	{};

};

template <typename Data, typename Unit>
void Timer<Data, Unit>::start()
{
	start_point = clock::now();
}

template <typename Data, typename Unit>
void Timer<Data, Unit>::finish()
{
	finish_point = clock::now();
	time = finish_point - start_point;
}

template <typename Data, typename Unit>
typename Timer<Data, Unit>::duration Timer<Data, Unit>::getTime()
{
	return time;
}

template <typename Data, typename Unit>
void Timer<Data, Unit>::printTime()
{
	std::cout << "time elapsed: " 
	<< std::fixed
	<< time.count() << '\n';
}