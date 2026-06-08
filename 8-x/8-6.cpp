#include <iostream>

int calculate(int x, int y, char z)
{
	switch(z)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '%':
		return x % y;
	default:
		std::cout << "calculate(): Unhandled case\n";
		return 0;
	}

}

int main()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter an other number: ";
	int y{};
	std::cin >> y;

	std::cout << "Enter the operator: ";
	char z{};
	std::cin >> z;

	int result{calculate(x, y, z)};
	std::cout << x << ' ' << z << ' ' << y << " is " << result << '\n';

	return 0;
}


