#include <iostream>
#include <limits>

int main()
{
	std::cout << std::boolalpha;
	std::cout << "float" << std::numeric_limits<float>::is_iec559 << '\n';
}
