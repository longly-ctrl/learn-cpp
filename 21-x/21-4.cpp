#include <iostream>

class Fraction
{
private:
	int m_a{0};
	int m_b{1};

public:
	Fraction(int a = 0, int b = 1)
		:m_a {a}
		,m_b {b}
		{
		
		}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2)
	{
		return Fraction {f1.m_a * f2.m_a , f1.m_b * f2.m_b};
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
	{
		out << f.m_a << " / " << f.m_b;

		return out;
	}

	friend std::istream& operator>>(std::istream& in, Fraction& f)
	{
		int a{};
		int b{};
		in >> a >> b;
		if(b == 0)
			in.setstate(std::ios_base::failbit);
		if(in)
			f = Fraction{a, b};

		return in;
	}
};

int main()
{
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	return 0;
}
