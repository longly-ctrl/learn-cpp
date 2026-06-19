#include <iostream>
#include <string_view>
#include <string>
#include <array>
#include "Random.h"
#include <algorithm>
#include <cassert>

struct Card
{
	enum Rank
	{
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,

		max_ranks
	};

	enum Suit
	{
		suit_club,
		suit_diamond,
		suit_heart,
		suit_spade,

		max_suits
	};

	static constexpr std::array allRanks {rank_ace, rank_2, rank_3, rank_4, rank_5,
		rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };

	static constexpr std::array allSuits { suit_club, suit_diamond, suit_heart, suit_spade };

	Rank rank{};
	Suit suit{};


	friend std::ostream& operator<<(std::ostream& out, const Card &card)
	{
		static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6',
			'7', '8', '9', 'T', 'J', 'Q', 'K' };
		static constexpr std::array suits { 'C', 'D', 'H', 'S' };
		out << ranks[card.rank] << suits[card.suit];
		return out;
	}

	int value() const
	{
		static constexpr std::array rankValues { 11, 2, 3, 4, 5, 6,
			7, 8, 9, 10, 10, 10, 10 };
		return rankValues[rank];
	}

			
};




class Deck
{
private:
	std::array<Card, 52> m_cards{};
	std::size_t m_nextCardIndex {0};

public:
	Deck()
	{
		std::size_t count{0};
		for(auto rank : Card::allRanks)
			for(auto suit : Card::allSuits)
				m_cards[count++] = Card { rank, suit };
	}

	void shuffle()
	{
		std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
		m_nextCardIndex = 0;
	}

	Card dealCard()
	{
		assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
		return m_cards[m_nextCardIndex++];
	}
};

struct Player
{
	int score{0};
};

namespace Settings 
{
	constexpr int bust{21};
	constexpr int dealerStopsAt{17};
}

bool dealerTurn(Deck &deck, Player &dealer)
{
	while(dealer.score < Settings::dealerStopsAt)
	{
		Card card{ deck.dealCard() };
		dealer.score += card.value();
		std::cout << "The dealer flips a " << card <<  ".  They now have " << dealer.score << '\n';
	}
	if(dealer.score > Settings::bust)
	{
		std::cout << "The dealer went bust!\n";
		return true;
	}

	return false;
}


bool playerTurn(Deck &deck, Player &player, Player &dealer)
{
	while(true)
	{
		std::cout << "(h) to hit, or (s) to stand: ";
		char input{};
		std::cin >> input;
		std::cin.clear();
		if(input == 'h')
		{
			Card card{deck.dealCard()};
			player.score += card.value();
			std::cout << "You were dealt " << card << ".  You know have " << player.score << '\n';
	
			if(player.score > Settings::bust)
			{
				std::cout << "You went bust!\n";
				return false;
			}
		}
		if(input == 's')
		{
			if(dealerTurn(deck, dealer))
				return true;
			if(player.score > dealer.score)
				return true;
			else
				return false;
		}
	}
}

bool playBlackjack()
{
	Deck deck{};
	deck.shuffle();

	Player dealer{deck.dealCard().value() };

	std::cout << "The dealer is showing: " << dealer.score << '\n';

	Player player{ deck.dealCard().value() + deck.dealCard().value() };

	std::cout << "You have score: " << player.score << '\n';

	if(playerTurn(deck, player, dealer))
		return true;
	else 
		return false;

}




int main()
{
	Deck deck{};
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	deck.shuffle();
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	if(playBlackjack())
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}

