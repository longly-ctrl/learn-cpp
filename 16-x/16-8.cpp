#include <iostream>
#include <vector>
#include <string>
#include <string_view>

void findName(std::string_view name, const std::vector<std::string> names)
{
	bool print{false};
	for(std::string_view str : names)
	{
		if( str == name)
		{
			print = true;
			break;
		}
	}
	if(print)
	{
		std::cout << name << " was found.\n";
	}else
	{
		std::cout << name << " was not found.\n";
	}

}

template <typename T>
bool isValidArray(const T& val, const std::vector<T>& arr)
{
	for(const auto& str : arr)
	{
		if(val == str)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	std::vector<std::string> names{"Alex", "Betty", "Caroline", 
		"Dave", "Emily", "Fred", "Greg", "Holly" };

	std::cout << "Enter a name: ";
	std::string name;
	std::cin >> name;

	findName(name, names);

	bool found{isValidArray(name, names)};

	if(found)
	{
		std::cout << name << " was found.\n";
	}else
	{
		std::cout << name << " was not found.\n";
	}

	

	return 0;
}


