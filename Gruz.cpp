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
		cout << "Неверный формат!" << endl;
	}
	else if (mas <= 0)
	{
		cout << "Масса должна быть больше нуля!" << endl;
	}
}


void Gruz:: Out(ofstream &ofst)
{
	ofst << " Грузоподъемность грузовика: " << mas << endl;
}

float Gruz::Ratio()
{
	return float(mas) / float(getPower());
}

void Gruz::OnlyGruz(ofstream &ofst)
{
	ofst << "Кол-во лошадиных сил : " << getPower() << ' ';
	Out(ofst);
}

void Gruz::MultiMethod(Cars *other, ofstream &ofst)
{
	other->MMGruz(ofst);
}

void Gruz::MMBus(ofstream &ofst)
{
	ofst << "Грузовик и автобус:" << endl;
}

void Gruz::MMGruz(ofstream &ofst)
{
	ofst << "Грузовик и грузовик:" << endl;
}

void Gruz::MMLeg(ofstream &ofst)
{
	ofst << "Грузовик и легковая:" << endl;
}