#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include "Random.h"

class Creature
{
protected:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_attack{};
	int m_gold{};

public:
	Creature(std::string name, char symbol, int health, int attack, int gold)
		:m_name{name}
		,m_symbol{symbol}
		,m_health{health}
		,m_attack{attack}
		,m_gold{gold}
		{
		}

	const std::string& getName() const {return m_name;}

	char getSymbol() const {return m_symbol;}

	int getHealth() const {return m_health;}

	int getAttack() const {return m_attack;}

	int getGold() const{return m_gold;}

	void reduceHealth(int i) { m_health -= i;}

	bool isDead() {return (m_health <= 0);}

	void addGold(int i) { m_gold += i;}
};

class Player : public Creature
{
private:
	int m_level{1};

public:
	Player(std::string name)
		:Creature(name, '@', 10, 1, 0)
		{
		}
	void levelUp() 
	{
		m_level += 1;
		m_attack += 1;
	}

	int getLevel() {return m_level;}

	bool hasWon() { return (m_level >= 20);}

};

class Monster : public Creature
{
public:
	enum Type
	{
		dragon,
		orc,
		slime,
		max_types
	};
private:
	static inline Creature monsterData[] = {
		{"dragon", 'D', 20, 4, 100},
		{"orc", 'o', 4, 2, 25},
		{"slime", 's', 1, 1, 10}
	};
	static_assert(std::size(monsterData) == max_types);
public:
	Monster(Monster::Type t)
		:Creature{monsterData[static_cast<std::size_t>(t)]}
	{
	}

	static Type getRandomMonster()
	{
		return static_cast<Monster::Type>(Random::get(0, max_types-1));
	}

};
void attackMonster(Player& player, Monster& m)
{
	if(player.isDead())
		return;
	m.reduceHealth(player.getAttack());
	std::cout << "You hit the " << m.getName() << " for " << player.getAttack() << " damage.\n";

	if(m.isDead())
	{
		std::cout << "You killed the " << m.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << ".\n";
		player.addGold(m.getGold());
		std::cout << "You found " << m.getGold() << " gold.\n";
	}
}



void attackPlayer(Player& player, Monster& m)
{
	if(m.isDead())
		return;

	player.reduceHealth(m.getAttack());
	std::cout << m.getName() << " hit you for " << m.getAttack() << " damage.\n";
}


void fightMonster(Player& player)
{
	Monster m{Monster::getRandomMonster()};
	std::cout << "You have encountered a " << m.getName() << " (" <<
		m.getSymbol() << ").\n";
	while(!m.isDead() && !player.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char c;
		std::cin >> c;
		if(c == 'r' || c =='R')
			if(Random::get(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return;
			}else
			{
				std::cout << "You failed to fled.\n";
				attackPlayer(player, m);
				continue;
			}
		if(c == 'f' || c == 'F')
		{
			attackMonster(player, m);
			attackPlayer(player, m);
		}
	}

	
}

int main()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;
	Player player{name};
	std::cout << "Welcome, " << player.getName() << '\n';

	while(!player.isDead() && !player.hasWon())
		fightMonster(player);

	if(player.isDead())
	{
		std::cout << "You died on level " << player.getLevel() << " and with " <<
			player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won the game with " << player.getGold() << " gold!\n";
	}

	return 0;
}



