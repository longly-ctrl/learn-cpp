#include <iostream>
#include <array>
#include <string_view>
#include <string>
#include "Random.h"
#include <limits>

namespace Potion
{
	enum Type
	{
		healing,
		mana,
		speed,
		invisibility,
		max_types
	};

	constexpr std::array costs{ 20, 30, 12, 50 };

	constexpr std::array types{ healing, mana, speed, invisibility };

	constexpr std::array<std::string_view, max_types> name{ "healing", "mana", "speed", "invisibility" };

	static_assert(std::size(costs) == max_types);
	static_assert(std::size(types) == max_types);
	static_assert(std::size(name) == max_types);

}
class Player
{
private:
	static constexpr int s_minStartingGold {80};
	static constexpr int s_maxStartingGold {120};
	std::string m_name{};
	int m_gold{};
	std::array<int, Potion::max_types> m_inventory {};
	
public:
	explicit Player(std::string_view name) 
		: m_name {name}
		, m_gold {Random::get(s_minStartingGold, s_maxStartingGold)}
		{}

	int gold() const {return m_gold;}
	int inventory(Potion::Type p) {return m_inventory[p];}
	bool buy(Potion::Type type) 
	{
		if(m_gold < Potion::costs[type])
		{
			return false;
		}
		m_gold -= Potion::costs[type];
		++m_inventory[type];
		return true;
	}
};



int charNumToInt(char c)
{
	return c - '0';
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Potion::Type whichPotion()
{
	std::cout << "Enter the number of the potion you'd like to buy, op 'q' to quit: ";
	char c;
	while(true)
	{
		std::cin >> c;
		if(!std::cin)
		{
			std::cin.clear();
			ignoreLine();
			continue;
		}

		if(!std::cin.eof() && std::cin.peek() != '\n')
		{
			std::cout << "I didn't understand what you said. Try again: ";
			ignoreLine();
			continue;
		}
		
		if(c == 'q')
			return Potion::max_types;

		int val{charNumToInt(c)};
		if(val >= 0 && val < Potion::max_types)
			return static_cast<Potion::Type>(val);
		std::cout << "I didn't understand what you said. Try again: ";
		ignoreLine();
	}

}

void shop(Player &player)
{
	while(true)
	{
		std::cout << "Here is our selection for today:\n";
		for(auto p : Potion::types)
		{
			std::cout << p << ") " << Potion::name[p] << " costs " << Potion::costs[p] << '\n';
		}

		Potion::Type which{whichPotion()};

		if(which == Potion::max_types)
			return;
		bool success{player.buy(which)};
		if(!success)
			std::cout << "You can not afford that.\n\n";
		else
			std::cout << "You purchased a potion of " << Potion::name[which] <<
				". You have " << player.gold() << " gold left.\n\n";
	}
}





void printInventory(Player& player)
{
	std::cout << "Your inventory contain:\n";
	for(auto p : Potion::types)
	{
		if(player.inventory(p) > 0)
			std::cout << player.inventory(p) << "x potion of " << Potion::name[p] << '\n';
	}
	std::cout << "You escaped with " << player.gold() << " gold remaining.\n";
}


int main()
{
	std::cout << "Welcome to Rosecoe's potion emporium!\n";
	std::cout << "Enter your name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	Player player {name};
	std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n\n";

	shop(player);

	printInventory(player);

	std::cout << "\nThanks for shopping at Rpscoe's potion emporium!\n";

	return 0;
}



