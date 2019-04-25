
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Car.h"
#include "Bus.h"
#include "Gruz.h"
#include "Leg.h"
#include <fstream>


using namespace std;


Cars* Cars:: In(ifstream &ifst)
{
	Cars *avto;
	int key;
	char od[] = "gruzovik";
	char dv[] = "avtobus";
	char lg[] = "legkovaya";
	char prov[10];
	ifst.getline(prov, 10, '\n');
	
	if (_stricmp(od, prov) == 0)
	{
		key = 1;
	}
	if (_stricmp(dv, prov) == 0)
	{
		key = 2;
	}
	if (_stricmp(lg, prov) == 0)
	{
		key = 3;
	}

	switch (key)  // â çàâèñèìîñòè, îò òîãî, ÷òî â êëþ÷å, òóäà è îòïðàèò íîâûå äàííûå 
	{
	case 1:
		avto = new Gruz;
		break;
	case 2:
		avto = new Bus;
		break;
	case 3:
		avto = new Leg;
		break;
	default:    // íåò ñîâïàäåíèé -> íåò çàïèñè
		return 0;
	}
	
	char str[10];
	ifst.getline(str, 10, '\n');
	avto->power = atoi(str);
  ifst.getline(str, 10, '\n');
	avto->exp = atof(str);
  
	avto->InData(ifst);
	return avto;

}

int Cars:: fr()        // â äîê
{
	return power;
}

float Cars::fr2()        
{
	return exp;
}

