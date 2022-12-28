#include <iostream>
#include "kursachh.h"
using namespace std;

int main()
{
	setlocale(0, "");
	int a;
	while (true)
	{
		cout << "Курсовая работа :(\n" << "\n";
		cout << "1.Типы данных и их внутреннее представление в памяти.\n";
		cout << "2.Одномерные статические массивы.\n";
		cout << "3.Двумерные статические массивы. Указатели.\n";
		cout << "4.Вектовые строки как массивы символов.\n" << "\n";
		cout << "Введите номер практической работы:\n";
		cin >> a;
		if (a == 0)
			break;
		switch (a)
		{
		case 1:
			lab1();
			cout << endl;
			system("cls");
			system("pause");
			break;
		case 2:
			lab2();
			cout << endl;
			system("cls");
			system("pause");
			break;
		case 3:
			lab3();
			cout << endl;
			system("cls");
			system("pause");
			break;
		case 4:
			lab4();
			cout << endl;
			system("cls");
			system("pause");
			break;
		}
	}
}
