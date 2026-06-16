#include <iostream>
#include <vector>
#include <cassert>

namespace Animals
{
	enum Animals
	{
		chicken,
		dog,
		cat,
		elepent,
		duck,
		snake,
		max_animals
	};
	const std::vector legs{ 2, 4, 4, 4, 2, 0 };

}

int main()
{
	assert(Animals::max_animals == std::size(Animals::legs));
	std::cout << "An elepent has " << Animals::legs[Animals::elepent] << " legs.\n";

	return 0;
}
