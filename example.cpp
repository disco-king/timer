#include "Timer.hpp"
#include <unistd.h>

/*
	a short example of Timer usage
*/

int main(int argc, char const *argv[])
{

	{
		Timer<int, MICRO> t;	// Declaring a Timer object
								// with spans of type int and measurment in microseconds.
								// It's also possible to use any scalar type.
		
		t.start();//starting the clock

		usleep(500);//see how much time the OS is stealing from you

		t.finish();//finishing the measurement

		std::cout << "by built-in print:\n";
		t.printTime();	// Built-in function to print time.

		std::cout << "by return from function:\n";
		int d = t.getTime();	// You can also get your time measurement
								// in a chosen data type.
		std::cout << "time elapsed: " 
		<< d << '\n';
	}

	std::cout << '\n';

	{
		//advanced stuff
		Timer<double, MICRO> t;

		t.start();

		usleep(100);

		t.finish();// first measurement, accessible by index 0

		usleep(200);

		t.finish();// second measurement, index 1

		usleep(300);

		t.finish();// third measurement, index 2

		double d = t.getTime(0); // gettingTime as usual, 0 is unnecessary
		std::cout << "first span: " << d << '\n';

		t.printTime(1, "second span: ");	// We can also set a prefix we want...

		t.printTime(2, "third span: ", 0);	// ...and even disable the newline,
		std::cout << std::endl;				// although I don't think it makes much sense.

		t.clearTimes(); // so we have a clear table
		try
		{
			t.getTime(); // won't work as we use vector.at()
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n'; // naturally, we get an exception
		}
		

	}

    return 0;
}

