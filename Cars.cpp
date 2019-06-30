#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Car.h"
#include "Bus.h"
#include "Gruz.h"
#include "Leg.h"
#include <fstream>
#include <iostream>

using namespace std;

Cars* Cars:: In(ifstream &ifst)
{
	Cars *ca;
	int key;
	char gr[] = "gruzovik";
	char av[] = "avtobus";
	char lg[] = "legkovaya";
	char prov[10];
	ifst.getline(prov, 10, '\n');
	if (_stricmp(gr, prov) != 0 and _stricmp(av, prov) != 0 and _stricmp(lg, prov) != 0)
	{
		cout << "�������� ������ ����������! \n";
	}
	
	if (_stricmp(gr, prov) == 0)
	{
		key = 1;
	}
	if (_stricmp(av, prov) == 0)
	{
		key = 2;
	}
	if (_stricmp(lg, prov) == 0)
	{
		key = 3;
	}

	switch (key)  // � �����������, �� ����, ��� � �����, ���� � ������� ����� ������ 
	{
	case 1:
		ca = new Gruz;
		break;
	case 2:
		ca = new Bus;
		break;
	case 3:
		ca = new Leg;
		break;
	default:    // ��� ���������� -> ��� ������
		return 0;
	}

	char tmp[10];
	ifst.getline(tmp, 10, '\n');
	ca->power = atoi(tmp);
	if (ifst.fail())
	{
		cout << "�������� ������!" << endl;
	}
	else if (ca->power <= 0)
	{
		cout << "�������� ������ ���� ������ ����!" << endl;
	}

	ifst.getline(tmp, 10, '\n');
	ca->exp = atof(tmp);
	if (ifst.fail())
	{
		cout << "�������� ������!" << endl;
	}
	else if (ca->exp <= 0)
	{
		cout << "������ ������� ���� ������ ����!" << endl;
	}

	ca->InData(ifst);
	return ca;
}

int Cars:: getPower()        // � ���
{
	return power;
}

float Cars::getExp()
{
	return exp;
}

bool Cars::Compare(Cars &a)
{
	return this->Ratio() < a.Ratio();
}

void Cars::OnlyGruz(ofstream &ofst)
{
	ofst << " - " << endl;
}