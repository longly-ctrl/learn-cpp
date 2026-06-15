#include <iostream>
#include <vector>

int main()
{
	std::vector<int> num(3);

	std::cout << "Enter 3 integers: ";
	std::cin >> num[0] >> num[1] >> num[2];

	std::cout << "The sum is : " << num[0] + num[1] + num[2] << '\n';
	std::cout << "The product is : " << num[0] * num[1] * num[2] << '\n';

	return 0;
}
