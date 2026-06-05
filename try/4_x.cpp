#include <iostream>

double getDouble()
{
	std::cout << "Enter a number: ";
	double x{};
	std::cin >> x;
	return x;
}

char getChar()
{
	std::cout << "Enter a mathematical symbol: ";
	char y{};
	std::cin >> y;
	return y;
}

int main()
{
	double x{getDouble()};
	double y{getDouble()};
	char z{getChar()};

	if(z == '+') {
		std::cout << x << " + " << y << " = " << x + y << '\n';
	}else if(z == '-') {
		std::cout << x << " - " << y << " = " << x - y << '\n';
	}else if(z == '*') {
		std::cout << x << " * " << y << " = " << x * y << '\n';
	}else if(z == '/') {
		std::cout << x << " / " << y << " = " << x / y << '\n';
	}else {
		std::cout << "Invalid symbol" << '\n';
	}

	return 0;
}


		



