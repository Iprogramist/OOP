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
		cout << "�������� ������!" << endl;
	}
	else if (speed <= 0)
	{
		cout << "�������� ������ ���� ������ ����!" << endl;
	}
}

void Leg::Out(ofstream &ofst)
{
	ofst << " ������������ �������� �/�: " << speed << endl;
}

float Leg::Ratio()
{
	return float(75) / float(getPower());
}