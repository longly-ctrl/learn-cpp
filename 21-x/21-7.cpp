#include <iostream>
#include <numeric>

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1)
		:m_numerator{numerator}
		,m_denominator{denominator}
		{
			reduce();
		}

		void reduce()
		{
			int gcd{std::gcd(m_numerator, m_denominator)};
			if(gcd)
			{
				m_numerator /= gcd;
				m_denominator /= gcd;
			}
		}

		friend std::ostream& operator<<(std::ostream& out, const Fraction& f)
		{
			out << f.m_numerator << " / " << f.m_denominator;

			return out;
		}

		friend bool operator==(const Fraction& f1, const Fraction& f2)
		{
			return (f1.m_numerator == f2.m_numerator && 
					f1.m_denominator == f2.m_denominator);
		}

		friend bool operator<(const Fraction& f1, const Fraction& f2)
		{
			return (f1.m_numerator * f2.m_denominator < 
					f2.m_numerator * f1.m_denominator);
		}

		friend bool operator!=(const Fraction& f1, const Fraction& f2)
		{
			return (!operator==(f1, f2));
		}
		
		friend bool operator>(const Fraction& f1, const Fraction& f2)
		{
			return operator<(f2, f1);
		}

		friend bool operator<=(const Fraction& f1, const Fraction& f2)
		{
			return (!operator>(f1, f2));
		}

		friend bool operator>=(const Fraction& f1, const Fraction& f2)
		{
			return (!operator<(f1, f2));
		}
};

int main()
{
	Fraction f1{3, 2};
	Fraction f2{5, 8};
	
	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " >= " : " not >= ") << f2 << '\n';

	return 0;
}
