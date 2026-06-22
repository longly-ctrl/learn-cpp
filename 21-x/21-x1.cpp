#include <iostream>

class Average
{
private:
	std::int32_t m_sum{0};
	int m_num{0};

public:
	Average(){}

	Average& operator+=(std::int32_t n)
	{
		m_sum += n;
		m_num += 1;

		return *this;
	}


	friend std::ostream& operator<<(std::ostream& out, const Average& avg)
	{
		if(avg.m_num == 0)
		{
			out << 0;
			return out;
		}
		out << static_cast<double>(avg.m_sum) / avg.m_num;
		return out;
	}

	
};

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n';

	avg += 8;
	std::cout << avg << '\n';

	avg += 24;
	std::cout << avg << '\n';

	avg += -10;
	std::cout << avg << '\n';

	(avg += 6) += 10;
	std::cout << avg << '\n';

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}



