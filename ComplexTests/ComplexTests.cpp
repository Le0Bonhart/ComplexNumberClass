#include "pch.h"
#include "CppUnitTest.h"
#include "..\ComplexNumberClass\Complex.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexTests
{
	TEST_CLASS(ComplexTests)
	{
	public:
		TEST_METHOD(Constructor)
		{
			Complex c = Complex(10, 5);
			Assert::IsTrue(c.GetReal() == 10);
			Assert::IsTrue(c.GetImaginary() == 5);
		}

		TEST_METHOD(ConstructorPolar)
		{
			Complex c = Complex(2, 3 * acos(-1)/4, true);
			Assert::IsTrue(c.GetReal() + sqrt(2) < 0.0001f);
			Assert::IsTrue(c.GetImaginary() - sqrt(2) < 0.0001f);
		}
		
		TEST_METHOD(FromFloat)
		{
			auto c1 = Complex(5.1f, 0);

			auto c2 = Complex(5.1f);

			Assert::IsTrue(c1 == c2);
		}

		TEST_METHOD(FromInt)
		{
			auto c1 = Complex(5, 0);

			auto c2 = Complex(5);

			Assert::IsTrue(c1 == c2);
		}

		TEST_METHOD(GetReal)
		{
			auto c = Complex(23.123f, 31.12f);
			float expected = 23.123f;

			float actual = c.GetReal();

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetReal)
		{
			auto c = Complex(23.123f, 31.12f);
			float expected = 5.f;

			c.SetReal(5);

			Assert::AreEqual(expected, c.GetReal());
		}

		TEST_METHOD(GetImaginary)
		{
			auto c = Complex(23.123f, 31.12f);
			float expected = 31.12f;

			float actual = c.GetImaginary();

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetImaginary)
		{
			auto c = Complex(23.123f, 31.12f);
			float expected = 5.f;

			c.SetReal(5);

			Assert::AreEqual(expected, c.GetReal());
		}

		TEST_METHOD(Add)
		{
			auto expected = Complex(7.5f, 12.7f);
			auto c1 = Complex(3, 8);
			auto c2 = Complex(4.5f, 4.7f);

			auto actual = c1 + c2;

			Assert::IsTrue((expected - actual).Abs() < 0.0001f);
		}

		TEST_METHOD(Sub)
		{
			auto expected = Complex(-1.5f, 3.3f);
			auto c1 = Complex(3, 8);
			auto c2 = Complex(4.5f, 4.7f);

			auto actual = c1 - c2;

			Assert::IsTrue((expected - actual).Abs() < 0.0001f);
		}

		TEST_METHOD(Mult)
		{
			auto expected = Complex(-24.1f, 50.1f);
			auto c1 = Complex(3, 8);
			auto c2 = Complex(4.5f, 4.7f);

			auto actual = c1 * c2;


			Assert::IsTrue((expected - actual).Abs() < 0.0001f);
		}

		TEST_METHOD(Div)
		{
			auto expected = Complex(1, -2);
			auto c1 = Complex(7, -4);
			auto c2 = Complex(3, 2);

			auto actual = c1 / c2;

			Assert::IsTrue((expected - actual).Abs() < 0.0001f);
		}

		TEST_METHOD(Pow)
		{
			auto expected = Complex(8, acos(-1), true);
			auto arg1 = ((2.f / 3.f) * acos(-1));
			auto c = Complex(4, arg1, true);
			float pow = 1.5f;

			auto actual = c ^ pow;
			
			Assert::IsTrue((expected - actual).Abs() < 0.0001f);
		}

		TEST_METHOD(Abs)
		{
			Complex a = Complex(-4.0, 3.0);
			auto res = a.Abs();
			Assert::IsTrue(res - 5 < 0.0001f);
		}

		TEST_METHOD(Arg)
		{
			Complex c = Complex(12, 4, true);
			Assert::IsTrue(c.Arg() - 4 < 0.0001);
		}

		TEST_METHOD(EqualComplex)
		{
			Complex a = Complex(5, 10);
			Complex b = Complex(5, 10);
			Complex c = Complex(-5, -10);
			Assert::IsTrue(a == b);
			Assert::IsFalse(a == c);
		}

		TEST_METHOD(EqualsInt)
		{
			Complex a = Complex(4, 0);
			int b = 4;
			Assert::IsTrue(a == b);
			a.SetImaginary(2.f);
			Assert::IsFalse(a == b);
		}

		TEST_METHOD(EqualsFloat)
		{
			Complex a = Complex(10, 0);
			float b = 10;
			Assert::IsTrue(a == b);
			a.SetImaginary(1);
			Assert::IsFalse(a == b);
		}
	};
}
