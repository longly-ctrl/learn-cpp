#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
private:
	std::string m_name{};
	std::string m_color{};

public:
	Fruit(std::string name, std::string color)
		:m_name{name}
		,m_color{color}
		{}
	
	std::string getName() const {return m_name;}

	std::string getColor() const {return m_color;}
	
	friend std::ostream& operator<<(std::ostream& out, const Fruit& f)
	{
		out << "(" << f.getName() << ", " << f.getColor() << ")";
		return out;
	}
	
};

class Apple : public Fruit
{
private:
	double m_fiber{};

public:
	Apple(std::string name, std::string color, double fiber)
		:Fruit{name, color}
		,m_fiber{fiber}
		{}
	
	double getFiber() const {return m_fiber;}

	friend std::ostream& operator<<(std::ostream& out, const Apple& f)
	{
		out << "Apple(" << f.getName() << ", " << f.getColor() << ", " << f.getFiber() <<  ")";
		return out;
	}

};

class Banana : public Fruit
{
public:
	Banana(std::string name, std::string color)
		:Fruit{name, color}
	{}

	friend std::ostream& operator<<(std::ostream& out, const Banana& f)
	{
		out << "Banana(" << f.getName() << ", " << f.getColor() << ")";
		return out;
	}

};

int main()
{
	const Apple a {"Red delicious" , "red", 4.2};
	std::cout << a << '\n';

	const Banana b { "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}
