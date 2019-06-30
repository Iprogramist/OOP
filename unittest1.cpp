#include "stdafx.h"
#include "CppUnitTest.h"
#include "..//laba1/Bus.h"
#include "..//laba1/Gruz.h"
#include "..//laba1/Leg.h"
#include "..//laba1/List.h"
#include "..//laba1/Car.h"
#include <string.h>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(In_lower)
{
public:

	TEST_METHOD(Test1_Gruz_mas)
	{
		Gruz* testing_type = new Gruz;
		ifstream test_file("../UnitTest1/TestFiles/In_low.txt");
		testing_type->InData(test_file);
		int actual = testing_type->mas;
		int expected = 2;
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2_Leg_speed)
	{
		Leg* testing_type = new Leg;
		ifstream test_file("../UnitTest1/TestFiles/In_low.txt");
		testing_type->InData(test_file);
		int actual = testing_type->speed;
		int expected = 2;
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3_bus_capacity)
	{
		Bus* testing_type = new Bus;
		ifstream test_file("../UnitTest1/TestFiles/In_low.txt");
		testing_type->InData(test_file);
		int actual = testing_type->capacity;
		int expected = 2;
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(In_higher)
{
public:

	TEST_METHOD(Test_cont_IN_OUT)
	{
		ifstream test_file_in("../UnitTest1/TestFiles/In_higher_1.txt");
		List* begin = new List;
		begin->In(test_file_in);
		ofstream test_file_out("../UnitTest1/TestFiles/In_higher_2.txt");
		begin->Out(test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest1/TestFiles/In_higher_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest1/TestFiles/In_higher_3.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(Out_lower)
{
public:

	TEST_METHOD(Test1_Bus)
	{
		Bus testing_type;
		testing_type.capacity = 3;
		ofstream test_file_out("../UnitTest1/TestFiles/Out_lower_Bus.txt");
		testing_type.Out(test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest1/TestFiles/Out_lower_Bus.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = " Вместимость пассажиров: 3";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test1_Leg)
	{
		Leg testing_type;
		testing_type.speed = 3;
		ofstream test_file_out("../UnitTest1/TestFiles/Out_lower_Leg.txt");
		testing_type.Out(test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest1/TestFiles/Out_lower_Leg.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = " Максимальная скорость а/м: 3";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test1_Gruz)
	{
		Gruz testing_type;
		testing_type.mas = 3;
		ofstream test_file_out("../UnitTest1/TestFiles/Out_lower_Gruz.txt");
		testing_type.Out(test_file_out);
		test_file_out.close();

		ifstream test_file_in("../UnitTest1/TestFiles/Out_lower_Gruz.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = " Грузоподъемность грузовика: 3";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(IN_OUT_higher)
{
public:

	TEST_METHOD(Test_cont_IN_OUT)
	{
		ifstream test_file_in("../UnitTest1/TestFiles/In_higher_1.txt");
		List* begin = new List;
		begin->In(test_file_in);
		ofstream test_file_out("../UnitTest1/TestFiles/In_Out_higher_2.txt");
		begin->Out(test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest1/TestFiles/In_Out_higher_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest1/TestFiles/In_Out_higher_3.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(Sort)
{
public:

	TEST_METHOD(Test_sort_IN_OUT)
	{

		ifstream test_file_in("../UnitTest1/TestFiles/In_higher_1.txt");
		List* begin = new List;
		begin->In(test_file_in);
		begin->Sort();
		ofstream test_file_out("../UnitTest1/TestFiles/Sort_2.txt");
		begin->Out(test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest1/TestFiles/Sort_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest1/TestFiles/Sort_3.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(Filter)
{
public:

	TEST_METHOD(Test_filter_IN_OUT)
	{
		ifstream test_file_in("../UnitTest1/TestFiles/In_higher_1.txt");
		List* begin = new List;
		begin->In(test_file_in);
		ofstream test_file_out("../UnitTest1/TestFiles/Filter_2.txt");
		int i = 1;
		while (begin != NULL)
		{
			begin->a->OnlyGruz(test_file_out);
			begin = begin->next;
			i++;
		}
		

		int expected = true;
		int actual = true;

		i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../UnitTest1/TestFiles/Filter_2.txt", "r");;
		FILE *file_2 = fopen("../UnitTest1/TestFiles/Filter_3.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(RatioCar_func)
{
public:

	TEST_METHOD(Test1_bus)
	{
		Bus testCar;
		testCar.capacity = 10;
		testCar.power = 5;

		int actual = testCar.Ratio();

		Assert::AreEqual(150, actual);
	}

	TEST_METHOD(Test2_gruz)
	{
		Gruz testCar;
		testCar.mas = 10;
		testCar.power = 5;

		int actual = testCar.Ratio();

		Assert::AreEqual(2, actual);
	}

	TEST_METHOD(Test3_leg)
	{
		Leg testCar;
		testCar.power = 5;

		int actual = testCar.Ratio();

		Assert::AreEqual(15, actual);
	}
	
};
