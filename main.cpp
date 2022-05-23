#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include "Timer.hpp"

#define TYPE std::vector
#define _ratio 10000
#define _vector TYPE

template <typename T>
void print_vec(T const &vec)
{
	std::cout << "size " << vec.size() << ' '
	<< " capacity " << vec.capacity() << '\n';
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
}


int main(int argc, char const *argv[])
{

	typedef std::chrono::system_clock clock;
	typedef std::chrono::time_point<clock> point;

	Timer<int, std::micro> t;

    std::vector<int> v;
    TYPE<int> vector;
    vector.assign(1100 * _ratio, 11);
    _vector<int> tmp(500 * _ratio, 5), tmp2(1000 * _ratio, 10), tmp3(1500 * _ratio, 15), tmp4(3000 * _ratio, 30);

	point start_p = clock::now();

	t.start();

    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.swap(tmp);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.swap(tmp3);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::swap(vector, tmp2);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    std::swap(vector, tmp4);
    v.push_back(vector[2]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());

	t.finish();

	point finish_p = clock::now();
	std::chrono::duration<int, std::micro> dur = finish_p - start_p;
	std::cout << "by manual templ: ";
	std::cout << "time elapsed: " 
	<< std::fixed
	<< dur.count() << '\n';

	std::cout << "by built-in print: ";
	t.printTime();

	// std::cout << "by return from function: ";
	// Timer<double, MILLI>::duration d = t.getTime();
	// std::cout << "time elapsed: " 
	// << std::fixed
	// << d.count() << '\n';

    return 0;
}

