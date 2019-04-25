#include "Car.h"
#include "List.h"
#include <fstream>

using namespace std;


void List:: Free()        //////// инициализация 
{
	if (this == 0)
		return;
	List *p = this;
	List *t;

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
		ofst << "Кол-во лошадиных сил: " << p1->a->fr() << ' ';
		ofst << "Отношение веса к мощности: " << p1->a->Ratio() << ' ';
		p1->a->Out(ofst);
		p1 = p1->next;
		i++;
	}
}

List::List()
{
	next = NULL;
	a = NULL;
}