#pragma once
#include <string>
#include <fstream>
using namespace std;
#ifndef _Car_
#define _Car_

class Cars
{
	int power;
public:
	static Cars* In(ifstream &ifst);
	int fr();
	virtual void Out(ofstream &ofst) = 0;
	virtual void InData(ifstream &ifst) = 0;
};

#endif