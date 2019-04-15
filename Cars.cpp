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
	char od[] = "gruzovik";
	char dv[] = "avtobus";
	char tmp[10];
	ifst.getline(tmp, 10, '\n');
	int key = 3;
	if (_stricmp(od, tmp) == 0)
	{
		key = 1;
	}
	if (_stricmp(dv, tmp) == 0)
	{
		key = 2;
	}

	switch (key)  
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