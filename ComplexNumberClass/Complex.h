#pragma once

struct ComplexData
{
	float _re;
	float _im;
};

union PackUnion
{
	ComplexData _data;
	long long _packed;
};

class Complex
{
private:
	float _re;
	float _im;
public:
	Complex();
	Complex(float a, float b, bool polar_form = false); //при polar_form == true первый аргумет - модуль, а второй - угол 
	Complex(float a);
	Complex(int a);
	Complex(long long packed);
	float GetReal();
	void SetReal(float value);
	float GetImaginary();
	void SetImaginary(float value); 
	void Unpack(long long packed);
	long long Pack();
	static Complex Add(const Complex& lhs, const Complex& rhs);
	static Complex Sub(const Complex& lhs, const Complex& rhs);
	static Complex Mult(Complex& lhs, Complex& rhs);
	static Complex Div(Complex& lhs, Complex& rhs);
	static Complex Pow(Complex& num, float pow);
	float Abs();
	float Arg();
	Complex operator + (Complex& rhs);
	Complex operator - (Complex& rhs);
	Complex operator * (Complex& rhs);
	Complex operator / (Complex& rhs);
	Complex operator ^ (float rhs);
	bool operator == (Complex& rhs);
	bool operator == (float rhs);
	bool operator == (int rhs);
	bool operator != (Complex& rhs);
	bool operator != (float rhs);
	bool operator != (int rhs);
};