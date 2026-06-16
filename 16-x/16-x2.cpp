#include <iostream>
#include <vector>
#include "Random.h"
#include <limits>

namespace WordList
{
	std::vector<std::string_view> words { "mystery", "broccoli", "account",
		"almost", "spaghetti", "opinion", "beautiful", "distance", "lugguage"};

	std::string_view getRandomWord()
	{
		return words[Random::get<std::size_t>(0, words.size() - 1)];
	}

}

class Session
{
private:
	std::string_view m_words{WordList::getRandomWord()};

public:
	std::string_view getWord() const {return m_words;};
};

void draw(const Session& s)
{
	std::cout << '\n';
	std::cout << "The word is: ";
	for([[maybe_unused]]auto c : s.getWord())
	{
		std::cout << "_";
	}
	std::cout << '\n';
}

char getGuess()
{
	while(true)
	{
		char c{};
		std::cout << "Enter your next letter: ";
		std::cin >> c;
		if(!std::cin)
		{
			std::cin.clear();
			std::cout << "That's wasn't a valid input. Try again.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
		if(c < 'a' || c > 'z')
		{
			std::cout << "That's wasn't a valid input. Try again.\n";
			continue;
		}
		return c;
	}
}




int main()
{
	std::cout << "Welcome to C++man(a variant of Hangman)" << '\n';
	std::cout << "To win: guess the word. To lose: run out of pluses." << '\n';

	Session s{};

	draw(s);
	char c{ getGuess() };
	std::cout << "You guessed: " << c << '\n';
	return 0;
}
