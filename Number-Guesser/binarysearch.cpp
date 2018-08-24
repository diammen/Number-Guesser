#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "binarysearch.h"
using std::cout;
using std::endl;
using std::cin;
using namespace std::chrono_literals;
using namespace std::this_thread;

// find the mid point between two numbers
int findMidPoint(int min, int max)
{
	return (min + max) / 2;
}