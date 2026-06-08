#include "constants.h"
#include <iostream>

int main()
{
	std::cout << "How many students are in your class?";
	int students{};
	std::cin >> students;

	if(students > Constants::maxClassSize)
		std::cout << "There are too many students in your class.";
	else
		std::cout << "your class isn't too large.";

	return 0;
}


