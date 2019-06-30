#include "Bus.h"
#include <fstream>
using namespace std;

void Bus::InData(ifstream &ifst)
{
	char str[10];
	ifst.getline(str,10, '\n');
	capacity = atoi(str);
}

void Bus:: Out( ofstream &ofst)
{
	ofst << " Вместимость пассажиров: " << capacity << endl;
}

void Bus::MultiMethod(Cars *other, ofstream &ofst)
{
	other->MMBus(ofst);
}

void Bus::MMBus(ofstream &ofst)
{
	ofst << "Автобус и автобус:" << endl;
}

void Bus::MMGruz(ofstream &ofst)
{
	ofst << "Автобус и грузовик:" << endl;
}