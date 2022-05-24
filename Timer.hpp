#pragma once

#include <sys/time.h>
#include <chrono>
#include <vector>
#include <iostream>

#define NANO std::nano
#define MICRO std::micro
#define MILLI std::milli
#define CENTI std::centi
#define DECI std::deci
#define SEC std::ratio<1>
#define DECA std::deca


template <typename Data = float,
		 typename Unit = std::micro,
		 typename Base = double>
class Timer
{

public:
	typedef std::chrono::system_clock clock;
	typedef std::chrono::time_point<clock> point;
	typedef std::chrono::duration<Base, Unit> duration;

private:
	point start_point;
	point finish_point;
	duration time;
	std::vector<Data> times;

public:

	void start();
	void finish();
	Data getTime(int index = 0);
	void printTime(int index = 0, std::string prefix = "time elapsed: ", bool endl = true);
	void clearTimes();

	Timer() : start_point(),
				finish_point()
	{};

};

#include "Timer.tpp"
