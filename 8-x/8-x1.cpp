#include <iostream>

namespace Constants
{
	constexpr double gravity{ 9.8 };
	constexpr double ground{0.0};

}


double getTowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

double calculateBallHeight(double towerHeight, int seconds)
{
	const double fallDistance{Constants::gravity * (seconds * seconds) / 2};
	const double ballHeight{towerHeight - fallDistance};

	if(ballHeight < Constants::ground)
	{
		return 0.0;
	}

	return ballHeight;
}

void printBallHeight(double ballHeight, int seconds)
{
	if(ballHeight > Constants::ground)
	{
		std::cout << "At " << seconds << " seconds, the ball is at height " <<
			ballHeight << " meters\n";
	}else
	{
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
	}
}

double calculateAndPrintBallHeight(double towerHeight, int seconds)
{
	const double ballHeight{calculateBallHeight(towerHeight, seconds)};
	printBallHeight(ballHeight, seconds);

	return ballHeight;
}

int main()
{
	const double towerHeight{getTowerHeight()};

	int seconds{0};
	while(calculateAndPrintBallHeight(towerHeight, seconds) > Constants::ground)
	{
		++seconds;
	}

	return 0;
}



	
