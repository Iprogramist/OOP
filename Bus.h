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
	float Ratio();
	void MultiMethod(Cars *other, ofstream &ofst);
	void MMBus(ofstream &ofst);
	void MMGruz(ofstream &ofst);
	void MMLeg(ofstream &ofst);
	Bus() {};
};

#endif