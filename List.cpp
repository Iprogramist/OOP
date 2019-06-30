#include "Car.h"
#include "List.h"
#include <fstream>
#include <iostream>

using namespace std;


void List:: Free()        //////// ������������� 
{
	if (this == 0)
	{
		return;
	}

	List *list = this;
	
	list->next = NULL;
	list->car = NULL;
	list = NULL;
}

void List::In(ifstream &ifst)
{
	int count = 0;
	List *end = this;

	while (!ifst.eof())
	{
		if (count == 0)
		{
			this->car = Cars::In(ifst);
			this->next = NULL;
			count++;
		}
		else
		{
			end->next = new List;
			end = end->next;
			end->car = Cars::In(ifst);
			end->next = NULL;
			count++;
		}
	}
}

void List::Out(ofstream &ofst)
{
	List *list = this;
	int i = 1;
	int  count = 0;
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	List *list1 = this;
	ofst << "��������� ��������! " << endl;
	ofst << "���������� ����: " << count << endl;
	while (list1 != NULL)
	{
		ofst << i << ": ";
		ofst <<"���-�� ��������� ���: " << list1->car->getPower() << ' ';
		ofst << "��������� ���� � ��������: " << list1->car->Ratio() << ' ';
		ofst << "������: " << list1->car->getExp() << ' ';
		list1->car->Out(ofst);
		list1 = list1->next;
		i++;
	}

	list1 = this;
	i = 1;
	ofst << "������ ���������: " << count << endl;
	while (list1 != NULL)
	{
		ofst << i << ": ";
		list1->car->OnlyGruz(ofst);
		list1 = list1->next;
		i++;
	}
}

List::List()
{
	next = NULL;
	car = NULL;
}

void List::Sort()
{
	char signOfCompare;
	bool check;
	cout << "\n��� �������������? �� ����������� (>) ��� �������� (<): ";
	cin >> signOfCompare;
	while (signOfCompare != '<' and signOfCompare != '>')
	{
		cout << "\n������! ������� < ��� > : ";
		cin >> signOfCompare;
	}
	switch (signOfCompare)
	{
		case '>':
		{
			check = 0;
			break;
		}
		case '<':
		{
			check = 1;
			break;
		}
		default:
		{
			cout << "������!" << endl;
		}
	}

	Cars* tmpCar;
	List* temp1;
	List * temp2;

	for (temp1 = (this); temp1; temp1 = temp1->next)
	{
		for (temp2 = (this); temp2; temp2 = temp2->next)
		{
			if ((temp1->car->Compare(*temp2->car)) - check)
			{
				tmpCar = temp1->car;
				temp1->car = temp2->car;
				temp2->car = tmpCar;
			}
		}
	}
}