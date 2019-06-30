#include "Gruz.h"
#include <fstream>
#include <iostream>

using namespace std;

void Gruz:: InData( ifstream &ifst)
{
	char str[10];
	ifst.getline(str, 10, '\n');
	mas = atoi(str);
	if (ifst.fail())
	{
		cout << "�������� ������!" << endl;
	}
	else if (mas <= 0)
	{
		cout << "����� ������ ���� ������ ����!" << endl;
	}
}


void Gruz:: Out(ofstream &ofst)
{
	ofst << " ���������������� ���������: " << mas << endl;
}

float Gruz::Ratio()
{
	return float(mas) / float(getPower());
}

void Gruz::OnlyGruz(ofstream &ofst)
{
	ofst << "���-�� ��������� ��� : " << getPower() << ' ';
	Out(ofst);
}

void Gruz::MultiMethod(Cars *other, ofstream &ofst)
{
	other->MMGruz(ofst);
}

void Gruz::MMBus(ofstream &ofst)
{
	ofst << "�������� � �������:" << endl;
}

void Gruz::MMGruz(ofstream &ofst)
{
	ofst << "�������� � ��������:" << endl;
}

void Gruz::MMLeg(ofstream &ofst)
{
	ofst << "�������� � ��������:" << endl;
}