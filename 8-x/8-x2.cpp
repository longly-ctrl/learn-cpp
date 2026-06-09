#include "Random.h"
#include <iostream>

bool playHiLo(int guesses, int min, int max)
{

	std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " <<
		max << ". You have " << guesses << " tires to guess what it is.\n";
	const int number{Random::get(min, max)};

	for(int count{1}; count <= guesses; ++count)
	{
		std::cout << "Guess #" << count << ": ";
		int guess{};
		std::cin >> guess;

		if(guess > number)
		{
			std::cout << "Your guess is too high.\n";
		}else if(guess < number)
		{
			std::cout << "Your guess is too low.\n";
		}else
		{
			std::cout << "Correct! You win!\n";
			return true;
		}
	}

	std::cout << "Sorry, you lose. The correct the number is " << number << '\n';
	return false;
}

bool playAgain()
{
	while(true)
	{
		std::cout << "Would you like to play again?(y/n)";
		char ch{};
		std::cin >> ch;

		switch(ch)
		{
		case 'y': 
			return true;
		case 'n':
			return false;
		}
	}
}


int main()
{
	constexpr int guesses{7};
	constexpr int min{1};
	constexpr int max{100};

	do
	{
		playHiLo(guesses, min, max);
	}while(playAgain());

	std::cout << "Thank you for play.\n";
	return 0;
}












