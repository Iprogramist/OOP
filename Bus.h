#pragma once
#include "Car.h"
#include <fstream>
using namespace std;
#ifndef _Bus_
#define _Bus_

class Bus : public Cars
{
	int capacity;
public:
	void Out(ofstream &ofst);
	void InData(ifstream &ifst);
	Bus() {};
};

#endif