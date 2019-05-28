#include <iostream>
#include <Windows.h>
#include <time.h>   
#include <fstream>
#include <string>
#include <vector>
#pragma warning(disable  : 4996)

using namespace std;

struct Working
{
	int code;
	string name1;
	string name2;
	string name3;
	int BrDay[3];
	string sex;
	int WrDay[3];	
	string position;
	int salary;
};

void Input(Working* working, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Код: ";
		cin >> working[i].code;

		cout << endl << "Фамилия: ";
		cin >> working[i].name1;		
		
		cout << endl << "Имя: ";
		cin >> working[i].name2;

		cout << endl << "Отчесво: ";
		cin >> working[i].name3;

		cout << endl << "Дата рождения число, месяц, год(через пробел): ";
		for (int j = 0; j < 3; j++)
		{			
			cin >> working[i].BrDay[j];
		}

		cout << endl << "Пол: ";
		cin >> working[i].sex;

		cout << endl << "Дата принятия на работу число, месяц, год(через пробел): ";
		for (int j = 0; j < 3; j++)
		{			
			cin >> working[i].WrDay[j];
		}

		cout << endl << "Должность: ";
		cin >> working[i].position;

		cout << endl << "Зараплата: ";
		cin >> working[i].salary;
		cout << endl;
	}	
}

void First(Working* working, int n)
{	
	int Date1[3], Date2[3], k = 0, sr = 0;

	cout << "Начало периода: ";
	for (int j = 0; j < 3; j++)
	{		
		cin >> Date1[j];
		if (j != 2)
			cout << ".";
	}

	cout << "Конец периода: ";
	for (int j = 0; j < 3; j++)
	{	
		cin >> Date2[j];	
		if (j != 2)
			cout << ".";
	}

	for (int i = 0; i < n; i++)
	{
		if (working[i].WrDay[2] >= Date1[2] && working[i].WrDay[2] <= Date2[2])
		{
			if (working[i].WrDay[1] >= Date1[1] && working[i].WrDay[1] <= Date2[1])
			{
				if (working[i].WrDay[0] >= Date1[0] && working[i].WrDay[0] <= Date2[0])
				{
					k++;
					sr += working[i].salary;
				}
			}
		}
	}
	if (k == 0)
		cout << "Таких сотрудников нету!!!";
	else
	{
		cout << "Количество сотрудников: " << k;
		cout << "Средняя зарплата: " << sr / k;
	}
	

}

void Min(Working* working, int n)
{
	int min;
	min = working[0].BrDay[0] + working[0].BrDay[1] * 30 + working[0].BrDay[2] * 361;
	for (int i = 0; i < n; i++)
	{
		if ((working[i].BrDay[0] + working[i].BrDay[1] * 30 + working[i].BrDay[2] * 361) < min)
		{
			cout << endl << "Код: " << working[i].code << endl << "ФИО: " << working[i].name1 << " " << working[i].name2 << " " << working[i].name3 << endl << "Дата рождения: " << working[i].BrDay[0] << "." << working[i].BrDay[1] << "." <<
				working[i].BrDay[2] << endl << "Пол: " << working[i].sex << endl << "Дата принятия на работу: " << working[i].WrDay[0] << "." << working[i].WrDay[1] << "." << working[i].WrDay[2] << endl << "Должность: " << working[i].position << endl << "Зарплата: " << working[i].salary;
		}
	}

}

void HoD(Working* working, int n)
{
	time_t t;
	time(&t);
	int year = localtime(&t)->tm_year;
	for (int i = 0; i < n; i++)
	{
		if ((year - working[i].BrDay[2]) % 5)
		{
			string Fail = "Юбиляры.txt";
			ofstream fail;
			fail.open(Fail);
			if (!fail.is_open())
			{
				cout << "Ошибка при открытии файла!!!";
			}
			else
			{
				fail << "Код: " << working[i].code << endl << "ФИО: " << working[i].name1 << " " << working[i].name2 << " " << working[i].name3 << endl << "Дата рождения: " << working[i].BrDay[0] << "." << working[i].BrDay[1] << "." <<
					working[i].BrDay[2] << endl << "Пол: " << working[i].sex << endl << "Дата принятия на работу: " << working[i].WrDay[0] << "." << working[i].WrDay[1] << "." << working[i].WrDay[2] << endl << "Должность: " << working[i].position << endl << "Зарплата: " << working[i].salary << endl << endl;
			}			
			fail.close();
		}
	}
}

int main()
{	
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите количество сотрудников: ";
	int n, k;
	cin >> n;
start:
	cout << "1 - Ввод данных/n2 - Сотрудники которые были приняты на роботу в указаный период/n3 - Самый молодой сотрудник/n4 - Юбиляры/n0 - Выход";
	cin >> k;
	Working* working = new Working[n];	
	switch(k)
	{
		case 1:
		{
			Input(working, n);
			goto start;
			break;
		}
		case 2:
		{
			First(working, n);
			goto start;
			break;
		}
		case 3:
		{
			Min(working, n);
			goto start;
			break;
		}
		case 4:
		{
			HoD(working, n);
			goto start;
			break;
		}
		default:
			break;
	};
	
	
	
	
}
