#include "Gruz.h"
#include <fstream>

using namespace std;

void Gruz:: InData( ifstream &ifst)
{
	char str[10];
	ifst.getline(str, 10, '\n');
	mas = atoi(str);
}


void Gruz:: Out(ofstream &ofst)
{
	ofst << " Грузоподъемность грузовика: " << mas << endl;
}

float Gruz::Ratio()
{
	return float(mas) / float(fr());
}

void Gruz::OnlyGruz(ofstream &ofst)
{
	ofst << "Кол-во лошадиных сил : " << fr() << ' ';
	Out(ofst);
}