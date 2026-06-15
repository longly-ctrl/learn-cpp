#include <iostream>
#include <algorithm>


void sort2(int& lesser, int& greater)
{
	if(lesser > greater)
		std::swap(lesser, greater);
}


int main()
{
	int x{7};
	int y{5};

	std::cout << x << ' ' << y << '\n';

	sort2(x, y);
	std::cout << x << ' ' << y << '\n';

	sort2(x, y);
	std::cout << x << ' ' << y << '\n';

	return 0;
}

