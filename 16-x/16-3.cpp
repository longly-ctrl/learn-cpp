#include <iostream>
#include <vector>

int main()
{
	std::vector<char> str {'h', 'e', 'l', 'l', 'o'};

	std::cout << "The array has " << std::size(str) << " elements.\n";

	std::cout << str[1] << str.at(1) << '\n';

	return 0;
}
