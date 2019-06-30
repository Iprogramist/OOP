#pragma once
#ifndef __List__
#define __List__

#include "Car.h"

class List
{
	Cars *car;
	List *next;

public:
	void Free();
	void In(ifstream &ifst);
	void Out(ofstream &ofst);
	void Sort();
	List();
	~List()
	{
		Free();
	}
};
	
#endif 
