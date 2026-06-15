#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
	double m_r{0.0};
	std::string m_color{"none"};

public:
	Ball(std::string_view color, double r)
		:m_color {color}
		,m_r {r}
	{
	}
	const std::string& getColor() const {return m_color; }
	double getR() const {return m_r;}
};

	void print(Ball& ball)
	{
		std::cout << "Ball (" << ball.getColor() << ", " << ball.getR() << ")\n";
	}
;


int main()
{
	Ball blue {"blue", 10.0};
	print(blue);

	Ball red {"red", 12.0};
	print(red);

	return 0;
}



