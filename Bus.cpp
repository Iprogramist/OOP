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

float Bus::Ratio()
{
	return float(capacity * 75) / float(fr());
}