#include "Complex.h"
#include <iostream>
#include <cmath>

#define Accuracy 0.0001f

Complex::Complex() : _re(0), _im(0) {}

Complex::Complex(float a, float b, bool polar_form):_re(0), _im(0)
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

Complex::Complex(float a) :_re(a), _im(0) {}

Complex::Complex(int a) :_re((float)a), _im(0) {}

Complex::Complex(long long packed)
{
	PackUnion pack;
	pack._packed = packed;
	_re = pack._data._re;
	_im = pack._data._im;
}

float Complex::GetReal()
{
	return _re;
}

void Complex::SetReal(float value)
{
	_re = value;
}

float Complex::GetImaginary()
{
	return _im;
}

void Complex::SetImaginary(float value)
{
	_im = value;
}

void Complex::Unpack(long long packed)
{
	PackUnion pack;
	pack._packed = packed;
	_re = pack._data._re;
	_im = pack._data._im;
}

long long Complex::Pack()
{
	PackUnion pack;
	pack._data = {_re, _im};
	return pack._packed;
}

Complex Complex::Add(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs._re + rhs._re, lhs._im + rhs._im);
}

Complex Complex::Sub(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs._re - rhs._re, lhs._im - rhs._im);
}

Complex Complex::Mult(Complex& lhs, Complex& rhs)
{
	return Complex(lhs.Abs() * rhs.Abs(), lhs.Arg() + rhs.Arg(), true);
}

Complex Complex::Div(Complex& lhs, Complex& rhs)
{
	if (rhs.Abs() == 0) throw "Zero Division";
	return Complex(lhs.Abs()/rhs.Abs(), lhs.Arg() - rhs.Arg(), true);
}

Complex Complex::Pow(Complex& num, float pow)
{
	return Complex(std::pow(num.Abs(), pow), num.Arg() * pow, true);
}

float Complex::Abs()
{
	return sqrt(_re*_re + _im*_im);
}

float Complex::Arg()
{
	if (!_re) return acos(-1);
	if (_re > 0) return atan(_im / _re);
	return acos(-1) + atan(_im / _re);
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

Complex Complex::operator^(float rhs)
{
	return Pow(*this, rhs);
}

bool Complex::operator==(Complex& rhs)
{
	return ((_re - rhs._re < Accuracy) && (_im - rhs._im < Accuracy));
}

bool Complex::operator==(float rhs)
{
	return ((_im < Accuracy) && (_re - rhs < Accuracy));
}

bool Complex::operator==(int rhs)
{
	return ((_im < Accuracy) && (_re - rhs) < Accuracy);
}

bool Complex::operator!=(Complex& rhs)
{
	return !(*this == rhs);
}

bool Complex::operator!=(float rhs)
{
	return !(*this == rhs);
}

bool Complex::operator!=(int rhs)
{
	return !(*this == rhs);
}

std::ostream& operator << (std::ostream& ofstr, Complex comp)
{
	return ofstr << comp.GetReal() << " + i*" << comp.GetImaginary();
}