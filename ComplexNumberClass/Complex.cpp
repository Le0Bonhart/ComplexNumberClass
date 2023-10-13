#include "Complex.h"

Complex::Complex(float a, float b, bool polar_form = false) 
{
	if (polar_form)
	{
		_re = a * cos(b);
		_im = a * sin(b);
	}
	else
	{
		_re = a;
		_im = b;
	}
}

Complex::Complex(float a)
{
	_re = a;
	_im = 0;
}

Complex::Complex(int a)
{
	_re = (float)a;
	_im = 0;
}

float Complex::GetReal()
{
	return _re;
}

void Complex::SetReal(float& value)
{
	_re = value;
}

float Complex::GetImaginary()
{
	return _im;
}

void Complex::SetImaginary(float& value)
{
	_im = value;
}

Complex Complex::Add(Complex& lhs, Complex& rhs)
{
	return Complex(lhs._re + rhs._re, lhs._im + rhs._im);
}

Complex Complex::Sub(Complex& lhs, Complex& rhs)
{
	return Complex(lhs._re - rhs._re, lhs._im - rhs._im);
}

Complex Complex::Mult(Complex& lhs, Complex& rhs)
{
	return Complex(lhs.Abs() * rhs.Abs(), lhs.Arg() + rhs.Arg(), true);
}

Complex Complex::Div(Complex& lhs, Complex& rhs)
{
	return Complex(lhs.Abs()/rhs.Abs(), lhs.Arg() - rhs.Arg(), true);
}

Complex Complex::Pow(Complex& num, float& pow)
{
	return Complex(std::pow(num.Abs(), pow), num.Arg() * pow);
}

float Complex::Abs()
{
	return sqrt(_re*_re + _im*_im);
}

float Complex::Arg()
{
	return _re ? atan(_im / _re) : acos(-1);
}

Complex Complex::operator+(Complex& rhs)
{
	return Add(*this, rhs);
}

Complex Complex::operator-(Complex& rhs)
{
	return Sub(*this, rhs);
}

Complex Complex::operator*(Complex& rhs)
{
	return Mult(*this, rhs);
}

Complex Complex::operator/(Complex& rhs)
{
	return Div(*this, rhs);
}

Complex Complex::operator^(float& rhs)
{
	return Pow(*this, rhs);
}

bool Complex::operator==(Complex& rhs)
{
	return ((_re == rhs._re) && (_im == rhs._im));
}

bool Complex::operator==(float& rhs)
{
	return ((!_im) && (_re == rhs));
}

bool Complex::operator==(int& rhs)
{
	return ((!_im) && (_re == rhs));
}

ostream& operator << (ostream& ofstr, Complex comp)
{
	return ofstr << comp.GetReal() << " + i*" << comp.GetImaginary();
}