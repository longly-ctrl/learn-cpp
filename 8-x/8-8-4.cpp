#include <iostream>

void printSpace(int x)
{
	while(x > 0)
	{
		std::cout << ' ' << ' ';
		--x;
	}
}

int main()
{
	int outer{1};
	while(outer <= 5)
	{
		int inter{5};

		while(inter >= 1)
		{
			if(inter <= outer)
			{
				std::cout << inter << ' ';
			}else
			{
				std::cout << ' ' << ' ';
			}
			--inter;
		}

		std::cout << '\n';

		++outer;

	}
	return 0;
}



