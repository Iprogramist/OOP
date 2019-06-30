#include "Bus.h"
#include <fstream>
#include <iostream>

using namespace std;

void Bus::InData(ifstream &ifst)
{
	char tmp[10];
	ifst.getline(tmp,10, '\n');
	capacity = atoi(tmp);
	if (ifst.fail())
	{
		cout << "�������� ������!" << endl;
	}
	else if (capacity <= 0)
	{
		cout << "����������� ������ ���� ������ ����!" << endl;
	}
}

void Bus:: Out( ofstream &ofst)
{
	ofst << " ����������� ����������: " << capacity << endl;
}

float Bus::Ratio()
{
	return float(capacity * 75) / float(getPower());
}

void Bus::MultiMethod(Cars *other, ofstream &ofst)
{
	other->MMBus(ofst);
}

void Bus::MMBus(ofstream &ofst)
{
	ofst << "������� � �������:" << endl;
}

void Bus::MMGruz(ofstream &ofst)
{
	ofst << "������� � ��������:" << endl;
}

void Bus::MMLeg(ofstream &ofst)
{
	ofst << "������� � ��������:" << endl;
}