#include "Leg.h"
#include <fstream>
#include <iostream>

using namespace std;

void Leg::InData(ifstream &ifst)
{
	char str[10];
	ifst.getline(str, 10, '\n');
	speed = atoi(str);
	if (ifst.fail())
	{
		cout << "Неверный формат!" << endl;
	}
	else if (speed <= 0)
	{
		cout << "Скорость должна быть больше нуля!" << endl;
	}
}

void Leg::Out(ofstream &ofst)
{
	ofst << " Максимальная скорость а/м: " << speed << endl;
}

float Leg::Ratio()
{
	return float(75) / float(getPower());
}