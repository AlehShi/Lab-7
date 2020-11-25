#pragma once
#include <iostream>
using namespace std;
class Fraction
{
private:
	long numerator;
	long denominator;
public:
	Fraction(long n = 0, long d = 1);
	virtual ~Fraction() {}
	Fraction(const Fraction& f);

	long GetNumerator() const;
	long GetDenominator() const;
	void SetFraction(long n, long d);

	void Reduce();

	Fraction operator + (const Fraction& f) const;
	Fraction operator + (long a) const;
	friend Fraction operator + (long a, const Fraction& f);

	Fraction operator - (const Fraction& f) const;
	Fraction operator - (long a) const;
	friend Fraction operator - (long a, const Fraction& f);

	Fraction operator * (const Fraction& f) const;
	Fraction operator * (long a) const;
	friend Fraction operator * (long a, const Fraction& f);

	Fraction operator / (const Fraction& f) const;
	Fraction operator / (long a) const;
	friend Fraction operator / (long a, const Fraction& f);


	Fraction operator - () const;

	bool operator == (const Fraction& f) const;

	bool operator != (const Fraction& f) const;

	bool operator > (const Fraction& f) const;

	bool operator < (const Fraction& f) const;

	bool operator >= (const Fraction& f) const;

	bool operator <= (const Fraction& f) const;


	double ToDouble() const;

	friend ostream& operator << (ostream& s, const Fraction& f);

};




