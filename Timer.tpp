#include "Timer.hpp"

template <typename Data, typename Unit, typename Base>
void Timer<Data, Unit, Base>::start()
{
	times.clear();
	start_point = clock::now();
}

template <typename Data, typename Unit, typename Base>
void Timer<Data, Unit, Base>::finish()
{
	finish_point = clock::now();
	time = finish_point - start_point;
	times.push_back(static_cast<Data>(time.count()));
}

template <typename Data, typename Unit, typename Base>
Data Timer<Data, Unit, Base>::getTime(int index)
{
	return times.at(index);
}

template <typename Data, typename Unit, typename Base>
void Timer<Data, Unit, Base>::printTime(int index, std::string prefix, bool endl)
{
	Data d = times.at(index);

	std::cout << prefix 
	<< std::fixed
	<< d
	<< (endl ? '\n' : '\0');
}

template <typename Data, typename Unit, typename Base>
void Timer<Data, Unit, Base>::clearTimes()
{
	times.clear();
}
