#include <iostream>

int main()
{
	char ch{'a'};
	while(ch <= 'z')
	{
		std::cout << ch << ' ';
		std::cout << static_cast<int>(ch) << '\n';
		++ch;
	}
	return 0;
}

