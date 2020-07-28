
#include <cstring>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <mmsystem.h>
#include <conio.h>
#include "Header.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	TCALC CALC;
	char expr[255];
	static double x[10];
	cout << "Курсовая работа на тему: Инженерный калькулятор" << endl << endl;
	cout << "Данный калькулятор поддерживает расчет арифметических выражений содержащие + - * /" << endl;
	cout << "Данный калькулятор поддерживает расчет тригонометрических функций,функций логарифма: sin(),cos(),tg(),ctg(),ln(),lg()" << endl;
	cout << "Данный калькулятор поддерживает расчет квадатного корня, експоненты, возвидения в степень" << endl;
	cout << "Для выхода из програмы введите 'bb' " << endl;
	cout << "\t\t\t\t\tРУКОВОДСТВО ПОЛЬЗОВАТЕЛЮ" << endl << endl;
	cout << "Для расчета тригонометрических функций и функций логарифма, необходимо указать функцию, затем в скобках указать аргумент" << endl;
	cout << "Для расчета тригонометрических функций ввод должен соответствовать виду: sin(1) или tg(12)" << endl;
	cout << "Для расчета функций логарифма ввод должен соответствовать виду: ln(12) или lg(2)" << endl;
	cout << "Для нахождения квадратного корня, необхожимо указать функцию, затем в скобках указать аргумент" << endl;
	cout << "Для расчета квадратного корня ввод доолжен соответствовать виду: sqrt(4)" << endl;
	cout << "Для расчета возведения в степень ввод должен соответстовать виду: 2^4" << endl << endl << endl;
	cout << "Введите выражение" << endl;
	cout << "" << endl;

	CALC.SetX((double *)&x);

	while (1)
	{
		//Ввод выражения в окно
		cout << ">>  ";
		cin.getline(expr, 255);

		// если "bb" то закрыться//////////////
		if (!strcmp(expr, "bb")) break;//ВЫХОД//
		///////////////////////////////////////

		try
		{
			CALC.Compile(expr);
			CALC.Evaluate();
			cout << "Ответ:    " << CALC.GetResult() << endl << endl; 					//Вывод ответа на экран
			cout << "" << endl;
		}
		catch (TError error)
		{

			cerr << error.error << " на " << error.pos << " месте " << endl << endl; // Печать ошибки
			continue;
		}
	}
	return 0;
}
