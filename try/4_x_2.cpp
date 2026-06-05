#include <iostream>

double highInTime(int time)
{
	double result{};
	result = 9.8 * time * time / 2;
	return result;
}

int main() 
{
	std::cout << "Enter the height of the tower in meters: ";
	double height;
	std::cin >> height;
	int i{0};
	for( i = 0; i < 6; i++)
	{
		double far = height - highInTime(i);

		if(far > 0)
		{
			std::cout << "At " << i <<" secounds, the ball is at height: " << far << " meters" << '\n';
		}else
		{

			std::cout << "At " << i <<" secounds, the ball is on the ground." << '\n';
		}
	}

	return 0;
}


