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
	C()	{}

	C(double re, double im)
	{
		this->re = re;
		this->im = im;
	}

	C(double re)
	{
		this->re = re;
		this->im = 0;
	}

	C(const C& c)
	{
		this->re = c.re;
		this->im = c.im;
	}
	//   Constructors

	//Methods
	double abs()	{return sqrt(re*re + im*im);}
	double abs2()	{return re*re + im*im;}
	//Methods


	//   Operators
	//+
	C operator+(C z)
	{			
		return C(	
			re + z.re, 
			im + z.im
		);
	}
	C operator+(double x) 
	{
		return C(	
			re + x, 
			im
		);
	}
	friend C operator+(double x, C z) 
	{	
		return C(	
			x + z.re,
			z.im
		);
	}

	//-
	C operator-(C z) 
	{
		return C(
			re - z.re,
			im - z.im
		);
	}
	C operator-(double x) 
	{
		return C(
			re - x,
			im
		);
	}
	friend C operator-(double x, C z) 
	{
		return C(
			x - z.re,
			z.im
		);
	}

	//*
	C operator*(C z) 
	{			
		return C(	
			re * z.re - im * z.im,
			re * z.im + im * z.re	
		);
	}
	C operator*(double x) 
	{		
		return C(	
			x * re,
			x * im
		);
	}
	friend C operator*(double x, C z) 
	{
		return C(
			x * z.re,
			x * z.im
		);
	}

	///
	C operator/(C z) 
	{
		double abs = z.abs();
		return C(
			(re * z.re + im * z.im) / abs,
			(im * z.re - re * z.im) / abs 
		);
	}
	C operator/(double x)
	{
		return C(
			re / x,
			im / x
		);
	}
	friend C operator/(double x, C z)
	{
		double abs = z.abs();
		return C(
			( x * z.re) / abs,
			(-x * z.im) / abs
		);
	}

	//==
	C operator==(C z)
	{
		return re == z.re && im == z.im;
	}
	C operator==(double x)
	{
		return re == x && im == 0;
	}
	friend C operator==(double x, C z)
	{
		return x == z.re && 0 == z.im;
	}


	//!=
	C operator!=(C z)
	{
		return re != z.re || im != z.im;
	}
	C operator!=(double x)
	{
		return re != x || im != 0;
	}
	friend C operator!=(double x, C z)
	{
		return x != z.re || 0 != z.im;
	}


	friend ostream& operator<< (ostream& out, const C& z)
	{
		out << z.re << ' ' << z.im;
		return out;
	}
	//   Operators

};
