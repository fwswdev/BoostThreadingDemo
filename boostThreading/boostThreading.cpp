// boostThreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>



void my_func(int c, int delay)
{
	int ctr;
	for (ctr = 0; ctr < 10; ctr++)
	{
		if (c == 1) cout << "\t\t";
		cout << c << " " << ctr << endl;
		boost::this_thread::sleep(boost::posix_time::milliseconds(delay));
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	boost::thread t1(my_func, 1, 300);
	boost::thread t2(my_func, 2, 700);
	t1.join();
	t2.join();
	getchar();
	return 0;
}

// eof

