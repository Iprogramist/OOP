#pragma once
#include <string>
#include <fstream>
using namespace std;
#ifndef _Car_
#define _Car_

class Cars
{
	int power;
	float exp;
public:
	static Cars* In(ifstream &ifst);
	int fr();
	float fr2();
	virtual void Out(ofstream &ofst) = 0;
	virtual void InData(ifstream &ifst) = 0;
	virtual void OnlyGruz(ofstream &ofst);
	virtual float Ratio() = 0;
};

#endif