#include <iostream>
#include <cassert>
#include <cstdint>
#include <cmath>

class FixedPoint2
{
private:
	std::int16_t m_a;
	std::int8_t m_b;

public:
	FixedPoint2(std::int16_t a = 0, std::int8_t b = 0)
		:m_a {a}, m_b {b}
	{
		if(m_a < 0 || m_b < 0)
		{
			if(m_a > 0)
				m_a = -m_a;
			if(m_b > 0)
				m_b = -m_b;
		}

		m_a += m_b / 100;
		m_b = m_b % 100;
	}

	FixedPoint2(double d) :
		FixedPoint2(
			static_cast<std::int16_t>(std::trunc(d)),
			static_cast<std::int8_t>(std::round(d * 100) - std::trunc(d) * 100)
		)
	{
	}

	explicit operator double() const
	{
		return m_a + (static_cast<double>(m_b) / 100);
	}

	friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& f)
	{
		out << static_cast<double>(f);
		return out;
	}

	 friend bool testDecimal(const FixedPoint2& f)
	{
		if(f.m_a >= 0)
			return f.m_b > 0 && f.m_b < 100;
		else 
			return f.m_b < 0 && f.m_b > -100;
	}

	friend bool operator==(const FixedPoint2& f1, const FixedPoint2& f2)
	{
		return f1.m_a == f2.m_a && f1.m_b == f2.m_b;
	}

	FixedPoint2 operator-()
	{
		return FixedPoint2{-static_cast<double>(*this)};
	}

	friend FixedPoint2 operator+(const FixedPoint2& f1, const FixedPoint2& f2)
	{
		return FixedPoint2{static_cast<double>(f1) + static_cast<double>(f2)};
	}
	friend std::istream& operator>>(std::istream& in, FixedPoint2& f)
	{
		double d;
		in >> d;
		f = FixedPoint2{d};

		return in;
	}

		
};

int main()
{
	FixedPoint2 a {34, 56};
	std::cout << a << '\n';
	std::cout << static_cast<double>(a) << '\n';
	assert(static_cast<double>(a) == 34.56);

	FixedPoint2 b{-2, 8};
	assert(static_cast<double>(b) == -2.08);

	FixedPoint2 c{2, -8};
	assert(static_cast<double>(c) == -2.08);

	FixedPoint2 d{-2, -8};
	assert(static_cast<double>(d) == -2.08);

	FixedPoint2 e{0, -5};
	assert(static_cast<double>(e) == -0.05);

	FixedPoint2 f{0, 10};
	assert(static_cast<double>(f) == 0.1);
	
	FixedPoint2 a1{ 1, 104 };
	std::cout << a1 << '\n';
	std::cout << static_cast<double>(a1) << '\n';
	assert(static_cast<double>(a1) == 2.04);
	assert(testDecimal(a1));

	FixedPoint2 b1{ 1, -104 };
	assert(static_cast<double>(b1) == -2.04);
	assert(testDecimal(b1));

	FixedPoint2 c1{ -1, 104 };
	assert(static_cast<double>(c1) == -2.04);
	assert(testDecimal(c1));

	FixedPoint2 d1{ -1, -104 };
	assert(static_cast<double>(d1) == -2.04);
	assert(testDecimal(d1));

	FixedPoint2 a2{ 0.01 };
	std::cout << a2 << '\n';
	assert(static_cast<double>(a2) == 0.01);

	FixedPoint2 b2{ -0.01 };
	assert(static_cast<double>(b2) == -0.01);

	FixedPoint2 c2{ 1.9 }; // make sure we handle single digit decimal
	assert(static_cast<double>(c2) == 1.9);

	FixedPoint2 d2{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	assert(static_cast<double>(d2) == 5.01);

	FixedPoint2 e2{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	assert(static_cast<double>(e2) == -5.01);

	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	FixedPoint2 f2 { 106.9978 }; // should be stored with base 107 and decimal 0
	assert(static_cast<double>(f2) == 107.0);

	// Handle case where the argument's decimal rounds to -100 (need to decrease base by 1)
	FixedPoint2 g2 { -106.9978 }; // should be stored with base -107 and decimal 0
	assert(static_cast<double>(g2) == -107.0);

	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a3{ -0.48 };
	assert(static_cast<double>(a3) == -0.48);
	assert(static_cast<double>(-a3) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a3;
	std::cout << "You entered: " << a3<< '\n';
	assert(static_cast<double>(a3) == 5.68);

	return 0;
}
