#include "Timer.hpp"

template <typename Data, typename Unit>
void Timer<Data, Unit>::start()
{
	times.clear();
	start_point = clock::now();
}

template <typename Data, typename Unit>
void Timer<Data, Unit>::finish()
{
	finish_point = clock::now();
	time = finish_point - start_point;
	times.push_back(time.count());
}

template <typename Data, typename Unit>
Data Timer<Data, Unit>::getTime(int index)
{
	return times.at(index);
}

template <typename Data, typename Unit>
void Timer<Data, Unit>::printTime(int index, std::string prefix, bool endl)
{
	Data d = times.at(index);

	std::cout << prefix 
	<< std::fixed
	<< d
	<< (endl ? '\n' : '\0');
}

template <typename Data, typename Unit>
void Timer<Data, Unit>::clearTimes()
{
	times.clear();
}