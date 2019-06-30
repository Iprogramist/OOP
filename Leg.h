#pragma once
#include "Car.h"
#include <fstream>
using namespace std;
#ifndef _Leg_
#define _Leg_

class Leg : public Cars
{
	int speed;
public:
	void Out(ofstream &ofst);
	void InData(ifstream &ifst);
	float Ratio();
	void MultiMethod(Cars *other, ofstream &ofst);
	void MMBus(ofstream &ofst);
	void MMGruz(ofstream &ofst);
	void MMLeg(ofstream &ofst);
	Leg() {};
};

#endif