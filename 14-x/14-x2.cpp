#include <iostream>

class Fraction
{
private:
	int m_numerator{0};
	int m_denominator{1};

public:
	explicit Fraction(int x=0, int y=1)
		:m_numerator{ x }
		,m_denominator{ y }
		{}


	 void getFraction()
	{
		std::cout << "Enter a value for numerator: ";
		std::cin >> m_numerator;
		std::cout << "Enter a value for denominator: ";
		std::cin >> m_denominator;
		std::cout << '\n';
	}

	Fraction multiply(const Fraction& f1) const
	{
		return { f1.m_numerator * m_numerator, m_denominator * f1.m_denominator};
	}

	void printFraction() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};
int main()
{
	Fraction f1{};
	f1.getFraction();
	Fraction f2{};
	f2.getFraction();

	std::cout << "Your fructions multiplied together: ";

	f1.multiply(f2).printFraction();
	return 0;
}

	
	

