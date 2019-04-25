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
	ofst << " Ãðóçîïîäúåìíîñòü ãðóçîâèêà: " << mas << endl;
}

void Gruz:: OnlyGruz(ofstream &ofst)
{
	ofst<<"Êîë-âî ëîøàäèíûõ ñèë : "<<fr()<< ' ';
	Out(ofst);
}
float Gruz::Ratio()
{
	return float(mas) / float(fr());
}