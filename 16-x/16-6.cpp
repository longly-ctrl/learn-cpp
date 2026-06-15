#include <vector>
#include <iostream>

int main()
{
	std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
	int length = arr.size();

	for(std::size_t i{0}; i < length; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

	return 0;
}


