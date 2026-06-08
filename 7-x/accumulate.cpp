#include <iostream>

int accumulate(int x)
{
	static int result{0};
	result += x;

	return result; 
}

int main()
{
	std::cout << accumulate(4) << '\n';
	std::cout << accumulate(3) << '\n';
	std::cout << accumulate(2) << '\n';
	std::cout << accumulate(1) << '\n';
	return 0;

}

