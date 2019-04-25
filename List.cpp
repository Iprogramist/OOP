
#include "Car.h"
#include "List.h"
#include <fstream>

using namespace std;


void List:: Free()        //////// ������������� 
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
	ofst << "��������� ��������! " << endl;
	ofst << "���������� ����: " << kol << endl;
	while (p1 != NULL)
	{
		ofst << i << ": ";
		ofst <<"���-�� ���������� ���: " << p1->a->fr() << ' ';
		ofst << "������: " << p1->a->fr2() << ' ';
    p1->a->OnlyGruz(ofst);
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

