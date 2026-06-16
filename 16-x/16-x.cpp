#include <iostream>
#include <cassert>
#include <vector>
#include <string_view>
#include <type_traits>
#include <limits>

namespace Items
{
	enum Type : int
	{
		helthPoint,
		torch,
		arrow,
		max_items
	};
}
		
 std::string_view getItemNamePlural(Items::Type type)
{
	switch(type)
	{
		case Items::helthPoint: return "helth points";
		case Items::torch: return "torches";
		case Items::arrow: return "arrows";
		default: return "???";
	}
}


std::string_view getItemNameSingular(Items::Type type)
{
	switch(type)
	{
		case Items::helthPoint: return "helth point";
		case Items::torch: return "torch";
		case Items::arrow: return "arrow";
		default: return "???";
	}
}

template <typename T>
constexpr std::size_t toUZ(T value)
{
	assert(std::is_integral<T>() || std::is_enum<T>());

	return static_cast<std::size_t>(value);
}


int countTotalValues(const std::vector<int>& v)
{
	int sum{0};
	for(int val : v)
	{
		sum += val;
	}
	return sum;
}

void printItemNumber(const std::vector<int>& num, Items::Type type)
{
	bool single{num[toUZ(type)] == 1};
	std::cout << "You have " << num[toUZ(type)] << ' ';
	std::cout << (single ? getItemNameSingular(type) : getItemNamePlural(type)) << '\n';
}
template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& v)
{
	std::size_t minIndex{0};
	std::size_t maxIndex{0};
	for(std::size_t index{1}; index < v.size(); ++index)
	{
		if(v[index] < v[minIndex])
			minIndex = index;
		if(v[index] > v[maxIndex])
			maxIndex = index;
	}

	return { minIndex, maxIndex };
}

template <typename T>
void printArray(const std::vector<T>& v)
{
	std::cout << "With array ( ";
	bool comma {false};
	for(T num : v)
	{
		if(comma)
			std::cout << ", ";
		std::cout << num;
		comma = true;
	}
	std::cout << " ):\n";
}

std::vector<int> getVector()
{
	std::cout << "Enter numbers to add (use -1 to stop): ";
	int x;
	std::vector<int> v;
	while(true)
	{
		std::cin >> x;
		if(x == -1)
			break;
		if(!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		v.push_back(x);
	}
		
	return v;
}

template <typename T>
void printMinMax(std::pair<std::size_t, std::size_t> m, const std::vector<T>& v)
{
	std::cout << "The min element has index " << m.first << " and value " << v[m.first] << '\n';
	std::cout << "The max element has index " << m.second << " and value " << v[m.second] << '\n';
}

int main()
{
	std::vector<int> num{ 1, 5, 10 };
	assert( std::size(num) == Items::max_items );
	for(int i = 0; i < Items::max_items; ++i)
	{
		auto type{static_cast<Items::Type>(i)};
		printItemNumber(num, type);
	}

	std::cout<< "You have " << countTotalValues(num) << " total items\n";

	std::vector v1{ 3, 8, 2, 5, 7, 8, 3 };
	std::vector v2{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

	printArray(v1);


	auto m1{findMinMaxIndices(v1)};
	auto m2{findMinMaxIndices(v2)};
	printMinMax(m1, v1);
	printArray(v2);
	printMinMax(m2, v2);
	std::vector v3{getVector()};
	auto m3{findMinMaxIndices(v3)};
	printArray(v3);
	printMinMax(m3, v3);
	
	return 0;
}


