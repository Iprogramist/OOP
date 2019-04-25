#include "Car.h"
#include "List.h"
#include <fstream>
#include <iostream>

using namespace std;


void List:: Free()        //////// инициализация 
{
	if (this == 0)
		return;
	List *p = this;
	

	p->next = NULL;
	p->a = NULL;
	p = NULL;
}

void List::In(ifstream &ifst)
{
	int kol = 0;
	List *end = this;

	while (!ifst.eof())
	{
		if (kol == 0)
		{
			this->a = Cars::In(ifst);
			this->next = NULL;
			kol++;
		}
		else
		{
			end->next = new List;
			end = end->next;
			end->a = Cars::In(ifst);
			end->next = NULL;
			kol++;
		}
	}
}

void List::Out(ofstream &ofst)
{
	List *p = this;
	int i = 1;
	int  kol = 0;
	while (p != NULL)
	{
		kol++;
		p = p->next;
	}
	List *p1 = this;
	ofst << "Контейнер заполнен! " << endl;
	ofst << "Количество Авто: " << kol << endl;
	while (p1 != NULL)
	{
		ofst << i << ": ";
		ofst <<"Кол-во лошадиных сил: " << p1->a->fr() << ' ';
		ofst << "Отношение веса к мощности: " << p1->a->Ratio() << ' ';
		ofst << "Расход: " << p1->a->fr2() << ' ';
		p1->a->Out(ofst);
		p1 = p1->next;
		i++;
	}

	p1 = this;
	i = 1;
	ofst << "Только Грузовики: " << kol << endl;
	while (p1 != NULL)
	{
		ofst << i << ": ";
		p1->a->OnlyGruz(ofst);
		p1 = p1->next;
		i++;
	}
}

List::List()
{
	next = NULL;
	a = NULL;
}

void List::Sort()
{
	char p;
	bool proverka;
	cout << "\nКак отсортировать? По возрастанию (>) или убыванию (<): ";
	cin >> p;
	switch (p)
	{
	case '>':
	{
		proverka = 0;
		break;
	}

	case '<':
	{
		proverka = 1;
		break;
	}
	default:
	{
		cout << "Ошибка!" << endl;
	}
	}

	Cars* t3;
	List* t1;
	List * t2;

	for (t1 = (this); t1; t1 = t1->next)
	{
		for (t2 = (this); t2; t2 = t2->next)
		{
			if ((t1->a->Compare(*t2->a)) - proverka)
			{
				t3 = t1->a;
				t1->a = t2->a;
				t2->a = t3;
			}
		}
	}
}