#pragma once
#include <iostream>
using namespace std;
class Complex
{
private:
	float _real;
	float _imaginary;
public:
	Complex(float a, float b);
	Complex(float a);
	Complex(int a);
	float GetReal();
	void SetReal(float& value);
	float GetImaginary();
	void SetImaginary(float& value);
	static Complex Add(Complex& lhs, Complex& rhs);
	static Complex Sub(Complex& lhs, Complex& rhs);
	static Complex Mult(Complex& lhs, Complex& rhs);
	static Complex Div(Complex& lhs, Complex& rhs);
	static Complex Pow(Complex& num, float& pow);
	float Abs();
	Complex operator + (Complex& rhs);
	Complex operator - (Complex& rhs);
	Complex operator * (Complex& rhs);
	Complex operator / (Complex& rhs);
	Complex operator ^ (float& rhs);
	Complex operator == (float& rhs);
	Complex operator == (int& rhs);
};