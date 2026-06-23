#include <iostream>
#include <limits>
#include "Random.h"
#include <cassert>

constexpr int g_consoleLines{25};
class Tile
{
private:
	int m_num{0};

public:
	Tile() = default;
	explicit Tile(int num)
		:m_num {num}
	{}

	int getNum() const {return m_num;}

	bool isEmpty() const {return m_num == 0;}

};

std::ostream& operator<<(std::ostream& out, Tile tile)
{
	if(tile.getNum() > 9)
		out << " " << tile.getNum() << " ";
	else if(tile.getNum() > 0)
		out << "  " << tile.getNum() << " ";
	else if(tile.getNum() == 0)
		out << "    ";
	return out;
}

class Direction
{
public:
	enum Type
	{
		up,
		down,
		left,
		right,
		maxDirections
	};
	
	Direction(Type type)
		: m_type {type}
	{}

	Type getType() const {return m_type;}

	Direction operator-() const
	{
		switch(m_type)
		{
		case up: return Direction{down};
		case down: return Direction{up};
		case left: return Direction{right};
		case right: return Direction{left};
		default: break;
		}
		assert(0 && "Unsupported direction was passed!");
		return Direction{up};
	}

	static Direction getRandomDirection()
	{
		return Direction{static_cast<Type>(Random::get(0, maxDirections-1))};
	}

	friend std::ostream& operator<<(std::ostream& out, Direction dir)
	{
		switch(dir.getType())
		{
			case Direction::up: return(out << "up");
			case Direction::down: return(out << "down");
			case Direction::left: return(out << "left");
			case Direction::right: return(out << "right");
		default: break;
		}
		assert(0 && "Unsupported direction was passed!");
		return(out << "unknown direction");
	}

private:
	Type m_type{};
};



struct Point
{
	int x{};
	int y{};

	friend bool operator==(Point a, Point b)
	{
		return a.x == b.x && a.y == b.y;
	}

	friend bool operator!=(Point a, Point b)
	{
		return (!operator==(a, b));
	}

	Point getAdjacentPoint(Direction dir) const
	{
		switch(dir.getType())
		{
			case Direction::up: return Point{x, y-1};
			case Direction::down: return Point{x, y+1};
			case Direction::left: return Point{x-1, y};
			case Direction::right: return Point{x+1, y};
			default: break;
		}
		assert(0 && "Unsupported direction was passed!");
		return *this;
	}
};



class Board
{
public:
	Board() = default;
	friend std::ostream& operator<<(std::ostream& out, const Board& b)
	{
		for(int i{0}; i < g_consoleLines; ++i)
			std::cout << '\n';
		for(int y{0}; y < s_size; ++y)
		{
			for(int x{0}; x < s_size; ++x)
				out << b.m_tiles[y][x];
			std::cout << '\n';
		}
		return out;
	}

	friend bool operator==(const Board& b1, const Board& b2)
	{
		for(int y = 0; y < s_size; ++y)
			for(int x = 0; x < s_size; ++x)
				if(b1.m_tiles[y][x].getNum() != b2.m_tiles[y][x].getNum())
					return false;
		return true;
	}
	Point getEmptyTilePos() const
	{
		for(int y = 0; y < s_size; ++y)
			for(int x = 0; x < s_size; ++x)
				if(m_tiles[y][x].isEmpty())
					return Point{x, y};
		assert(0 && "There is no empty tile in the board!");
		return {-1,-1};
	}

	static bool isValidTilePos(Point p) 
	{
		return (p.x >= 0 && p.x < s_size)
			&& (p.y >= 0 && p.y < s_size);
	}

	void swapTiles(Point p1, Point p2)
	{
		std::swap(m_tiles[p1.y][p1.x], m_tiles[p2.y][p2.x]);
	}

	bool moveTile(Direction dir)
	{
		Point emptyTile{getEmptyTilePos()};
		Point adj{emptyTile.getAdjacentPoint(-dir)};

		if(!isValidTilePos(adj))
			return false;
		swapTiles(adj, emptyTile);
		return true;
	}

	bool playerWon() const
	{
		static Board s_solved{};
		return *this == s_solved;
	}

	void randomize()
	{
		for(int i = 0; i < 1000; )
			if(moveTile(Direction::getRandomDirection()))
				++i;
	}
private:
	static constexpr int s_size{4};
	Tile m_tiles[s_size][s_size] = {
		Tile{1}, Tile{2}, Tile{3}, Tile{4},
		Tile{5}, Tile{6}, Tile{7}, Tile{8},
		Tile{9}, Tile{10}, Tile{11}, Tile{12},
		Tile{13}, Tile{14}, Tile{15}, Tile{0}
	};

};




namespace UserInput
{
	bool isValidCommand(char ch)
	{
		return ch == 'w'
			|| ch == 'a'
			|| ch == 's'
			|| ch == 'd'
			|| ch == 'q';
	}

	void ignoreLine()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	char getChar()
	{
		char c;
		std::cin >> c;
		ignoreLine();
		return c;
	}

	char getCommandFromUser()
	{
		char c{};
		while(!isValidCommand(c))
		{
			c = getChar();
		}
		return c;
	}

	Direction charToDirection(char ch)
	{
		switch(ch)
		{
		case 'w': return Direction{Direction::up};
		case 's': return Direction{Direction::down};
		case 'a': return Direction{Direction::left};
		case 'd': return Direction{Direction::right};
		}
		assert(0 && "Unsupported direction was passed!");
		return Direction{Direction::up};
	}

};


int main()
{
    Board board{};
    board.randomize();
    std::cout << board;

    while (!board.playerWon())
    {
        char ch{ UserInput::getCommandFromUser() };

        // Handle non-direction commands
        if (ch == 'q')
        {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        // Handle direction commands
        Direction dir{ UserInput::charToDirection(ch) };

        bool userMoved{ board.moveTile(dir) };
        if (userMoved)
            std::cout << board;
    }

    std::cout << "\n\nYou won!\n\n";
    return 0;

}
