#include <iostream>

using namespace std;

class C
{
	public:
	double re;
	double im;

	//   Constructors
	C();
	C(double re, double im);
	C(double re);
	C(const C& c);
	//   Constructors

	//Methods
	double abs();
	double abs2();
	//Methods


	//   Operators
	//+
	C operator+(C z);
	C operator+(double x);
	friend C operator+(double x, C z);

	//-
	C operator-(C z);
	C operator-(double x);
	friend C operator-(double x, C z);

	//*
	C operator*(C z);
	C operator*(double x);
	friend C operator*(double x, C z);

	///
	C operator/(C z);
	C operator/(double x);
	friend C operator/(double x, C z);

	//==
	C operator==(C z);
	C operator==(double x);
	friend C operator==(double x, C z);

	//!=
	C operator!=(C z);
	C operator!=(double x);
	friend C operator!=(double x, C z);


	friend ostream& operator<< (ostream& out, const C& z);
	//   Operators

};
