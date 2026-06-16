#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <string_view>

int main()
{
	std::vector<int> num{ 3, 5, 7, 11, 13, 17, 19 };
	std::vector<std::string_view> str{ "fizz", "buzz", "pop", "bang",
				"jazz", "pow", "boom" };

	assert(num.size() == str.size());

	for(int i{1}; i <= 150; ++i)
	{
		bool print {false};
		for(std::size_t index{0}; index < num.size(); ++index)
		{
			if(i % num[index] == 0)
			{
				std::cout << str[index];
				print = true;

			}
		}
		if(!print)
		{
			std::cout << i;
		}

		std::cout << '\n';
	}
}
		


