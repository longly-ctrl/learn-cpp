#include <iostream>

int main()
{
	int outer{5};
	while(outer > 0)
	{
		int inter{outer};
		while(inter > 0)
		{
			std::cout << inter << ' ';
			--inter;
		}
		std::cout << '\n';
		--outer;
	}
	return 0;
}

