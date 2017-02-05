#include <iostream>
#include <cstdlib>
#include <math.h>

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


//   Constructors
C::C()	{}
	C::C(double re, double im)
{
	this->re = re;
	this->im = im;
}
	C::C(double re)
{
	this->re = re;
	this->im = 0;
}
	C::C(const C& c)
{
	this->re = c.re;
	this->im = c.im;
}
//   Constructors

//Methods
double C::abs()	{return sqrt(re*re + im*im);}
double C::abs2()	{return re*re + im*im;}
//Methods

//   Operators
//+
C C::operator+(C z)
{			
	return C(	
		re + z.re, 
		im + z.im
	);
}
C C::operator+(double x) 
{
	return C(	
		re + x, 
		im
	);
}
C operator+(double x, C z) 
{	
	return C(	
		x + z.re,
		z.im
	);
}
//-
C C::operator-(C z) 
{
	return C(
		re - z.re,
		im - z.im
	);
}
C C::operator-(double x) 
{
	return C(
		re - x,
		im
	);
}
C operator-(double x, C z) 
{
	return C(
		x - z.re,
		z.im
	);
}
//*
C C::operator*(C z) 
{			
	return C(	
		re * z.re - im * z.im,
		re * z.im + im * z.re	
	);
}
C C::operator*(double x) 
{		
	return C(	
		x * re,
		x * im
	);
}
C operator*(double x, C z) 
{
	return C(
		x * z.re,
		x * z.im
	);
}

///
C C::operator/(C z) 
{
	double abs2 = z.abs2();
	return C(
		(re * z.re + im * z.im) / abs2,
		(im * z.re - re * z.im) / abs2 
	);
}
C C::operator/(double x)
{
	return C(
		re / x,
		im / x
	);
}
C operator/(double x, C z)
{
	double abs2 = z.abs2();
	return C(
		( x * z.re) / abs2,
		(-x * z.im) / abs2
	);
}

//==
C C::operator==(C z)
{
	return re == z.re && im == z.im;
}
C C::operator==(double x)
{
	return re == x && im == 0;
}
C operator==(double x, C z)
{
	return x == z.re && 0 == z.im;
}

//!=
C C::operator!=(C z)
{
	return re != z.re || im != z.im;
}
C C::operator!=(double x)
{
	return re != x || im != 0;
}
C operator!=(double x, C z)
{
	return x != z.re || 0 != z.im;
}

ostream& operator<< (ostream& out, const C& z)
{
	out << z.re << ' ' << z.im;
	return out;
}
//   Operators
