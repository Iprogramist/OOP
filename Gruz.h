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
	Gruz() {};
};

#endif