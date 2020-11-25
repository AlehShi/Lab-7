#include "Fraction.h"
#include <iostream>
#include <cmath> 
using namespace std;

Fraction::Fraction(long n, long d)
{
	SetFraction(n, d);
}

Fraction::Fraction(const Fraction& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
}


long Fraction::GetNumerator() const
{
	return numerator;
}
long Fraction::GetDenominator() const
{
	return denominator;
}

void Fraction::SetFraction(long n, long d)
{
	if (d == 0)
	{
		throw exception("Zero denominator");
	}
	if (d < 0)
	{
		numerator = -1 * n;
		denominator = -1 * d;
	}
	else
	{
		numerator = n;
		denominator = d;
	}
	if (n == 0)
	{
		denominator = 1;
	}
	Reduce();
}

void Fraction::Reduce()
{
	long a, b, r;
	a = abs(numerator);
	b = abs(denominator);
	if (a < b)
	{
		r = a;
		a = b;
		b = r;
	}
	while (b > 0)
	{
		r = a % b;
		if (r < b)
		{
			a = b;
			b = r;
		}
		else
		{
			a = r;
		}
	}
	numerator /= a;
	denominator /= a;

}

Fraction Fraction::operator + (const Fraction& f) const
{
	return Fraction(numerator * f.denominator + f.numerator * denominator, denominator * f.denominator);
}
Fraction Fraction::operator + (long a) const
{
	return Fraction(numerator + a * denominator, denominator);
}
Fraction operator + (long a, const Fraction& f)
{
	return f.operator + (a);
}

Fraction Fraction::operator - (const Fraction& f) const
{
	return Fraction(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
}
Fraction Fraction::operator - (long a) const
{
	return Fraction(numerator - a * denominator, denominator);
}
Fraction operator - (long a, const Fraction& f)
{
	Fraction temp;
	temp = f.operator-(a);
	return temp.operator - ();
}

Fraction Fraction::operator * (const Fraction& f) const
{
	return Fraction(numerator * f.numerator, denominator * f.denominator);
}
Fraction Fraction::operator * (long a) const
{
	return Fraction(numerator * a, denominator);
}
Fraction operator * (long a, const Fraction& f)
{
	return f.operator * (a);
}

Fraction Fraction::operator / (const Fraction& f) const
{
	return Fraction(numerator * f.denominator, denominator * f.numerator);
}
Fraction Fraction::operator / (long a) const
{
	return Fraction(numerator, a * denominator);
}
Fraction operator / (long a, const Fraction& f)
{
	return Fraction(a * f.denominator, f.numerator);
}


Fraction Fraction::operator - () const
{
	return Fraction(-numerator, denominator);
}


bool Fraction::operator == (const Fraction& f) const
{
	return ((numerator == f.numerator) && (denominator == f.denominator));
}
bool Fraction::operator != (const Fraction& f) const
{
	return ((numerator != f.numerator) && (denominator != f.denominator));
}
bool Fraction::operator > (const Fraction& f) const
{
	return (numerator * f.denominator > denominator * f.numerator);
}
bool Fraction::operator <= (const Fraction& f) const
{
	return (!this->operator>(f));
}
bool Fraction::operator < (const Fraction& f) const
{
	return (numerator * f.denominator < denominator* f.numerator);
}
bool Fraction::operator >= (const Fraction& f) const
{
	return (!this->operator<(f));
}

double Fraction::ToDouble() const
{
	return (double)numerator / denominator;
}

ostream& operator << (ostream& s, const Fraction& f)
{
	s << f.numerator << "/" << f.denominator;
	return s;
}





