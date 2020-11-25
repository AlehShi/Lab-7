#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	long n1 = -5, d1 = -11, n2 = 20, d2 = -22;
	Fraction f1(n1, d1), f2(n2, d2);
	cout << "f1=" << f1 << endl;
	cout << "f1=" << f2 << endl << endl;

	Fraction f3 = f1 + f2;
	cout << f1 << " + " << f2 << " = " << f3 << endl;
	f3 = f1 - f2;
	cout << f1 << " - " << f2 << " = " << f3 << endl;
	f3 = f1 * f2;
	cout << f1 << " * " << f2 << " = " << f3 << endl;
	f3 = f1 / f2;
	cout << f1 << " / " << f2 << " = " << f3 << endl;

	f1.SetFraction(1, 2);
	long a = 3;
	f3 = a + f1;
	cout << a << " + " << f1 << " = " << f3 << endl;
	f3 = a - f1;
	cout << a << " - " << f1 << " = " << f3 << endl;
	f3 = f1 * a;
	cout << f1 << " * " << a << " = " << f3 << endl;
	f3 = f1 / a;
	cout << f1 << " / " << a << " = " << f3 << endl;
	cout << "f1 = " << f1 << endl;
	cout << "-f1 = " << -f1 << endl;

	cout << endl << "Сравнеие дробей" << endl;
	f1.SetFraction(3, 6);
	f2.SetFraction(10, 20);

	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;

	if (f1 == f2)
	{
		cout << "Дроби равны" << endl << endl;
	}

	f1.SetFraction(2, -1);
	f2.SetFraction(1, 3);

	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;

	if (f1 > f2)
	{
		cout << "f1 > f2" << endl << endl;
	}
	else
	{
		cout << "f1 <= f2" << endl << endl;
	}
	f1.SetFraction(19, 20);
	f2.SetFraction(19, 20);

	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;

	if (f1 >= f2)
	{
		cout << "f1 >= f2" << endl << endl;
	}
	else
	{
		cout << "f1 < f2" << endl << endl;
	}


	cout << "Приведение к double дроби 1/2" << endl;
	f1.SetFraction(1, 2);
	cout << f1.ToDouble() << endl;

	cout << "Пробуем ввести дробь 2/0" << endl;
	try
	{
		f1.SetFraction(2, 0);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}