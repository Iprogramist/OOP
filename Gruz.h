#pragma once
#include "Car.h"
#include <fstream>

using namespace std;

#ifndef _Gruz_
#define _Gruz_

class Gruz : public Cars
{
	int mas;
public:
	void Out(ofstream &ofst);
	void InData(ifstream &ifst);
	float Ratio();
	void OnlyGruz(ofstream &ofst);
	void MultiMethod(Cars *other, ofstream &ofst);
	void MMBus(ofstream &ofst);
	void MMGruz(ofstream &ofst);
	void MMLeg(ofstream &ofst);
	Gruz() {};
};

#endif