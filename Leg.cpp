#include "Leg.h"
#include <fstream>
using namespace std;

void Leg::InData(ifstream &ifst)
{
	char str[10];
	ifst.getline(str, 10, '\n');
	speed = atoi(str);
}

void Leg::Out(ofstream &ofst)
{
	ofst << " Максимальная скорость а/м: " << speed << endl;
}
