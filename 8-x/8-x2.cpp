#include "Random.h"
#include <limits>
#include <iostream>

int getGuess(int count, int min, int max)
{
	while(true)
	{
		std::cout << "Guess #" << count << ": ";
		int guess{};
		std::cin >> guess;

		bool success{std::cin};
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if(!success || guess < min || guess > max)
			continue;

		return guess;
	}
}



bool playHiLo(int guesses, int min, int max)
{

	std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " <<
		max << ". You have " << guesses << " tires to guess what it is.\n";
	const int number{Random::get(min, max)};

	for(int count{1}; count <= guesses; ++count)
	{
		int guess{getGuess(count, min, max)};

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

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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












