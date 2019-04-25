#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Car.h"
#include "Bus.h"
#include "Gruz.h"
#include <fstream>


using namespace std;


Cars* Cars:: In(ifstream &ifst)
{
	Cars *avto;
	int key;
	char od[] = "gruzovik";
	char dv[] = "avtobus";
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

	switch (key)  // в зависимости, от того, что в ключе, туда и отпраит новые данные 
	{
	case 1:
		avto = new Gruz;
		break;
	case 2:
		avto = new Bus;
		break;
	default:    // нет совпадений -> нет записи
		return 0;
	}
	
	char str[10];
	ifst.getline(str, 10, '\n');
	avto->power = atoi(str);
	avto->InData(ifst);
	return avto;

}

int Cars:: fr()        // в док
{
	return power;
}


bool Cars:: Compare(Cars &a)
{
	return this->Ratio() < a.Ratio();
}