#include <vector>
#include <iostream>
#include <limits>

template <typename T>
void printArray(const std::vector<T>& arr)
{
	for(std::size_t i{0}; i < arr.size(); ++i)
	{
		std::cout << arr[i] << ' ';
	}
	if(arr.size())
	{
		std::cout << '\n';
	}
}

template <typename T>
T getValidNumber(std::string_view prompt, T low, T high)
{
	T num{};
	do
	{
		std::cout << prompt;
		std::cin >> num;

		if(!std::cin) { std::cin.clear();}
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}while(num > high || num < low);

	return num;
}

template <typename T>
int findIndex(T val, const std::vector<T>& arr)
{
	for(std::size_t index{0}; index < arr.size(); ++index)
	{
		if(val == arr[index])
			return static_cast<int>(index);
	}
	return -1;
}

template <typename T>
T findMax(const std::vector<T>& arr)
{
	T max{};
	for(std::size_t index{}; index < arr.size(); ++index)
	{
		if(max < arr[index])
		{
			max = arr[index];
		}
	}
	return max;
}


int main()
{
	std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

	int num{getValidNumber("Enter a number between 1 and 9: ", 1, 9)};

	int index{findIndex(num, arr)};

	printArray(arr);
	
	if(index == -1)
	{
		std::cout << "The number " << num << " was not find.\n";
	}else
	{
		std::cout << "The number " << num << " has index " << index << '\n';
	}

	std::vector arr1{4.4, 6.6, 3.3, 7.7, 8.8, 2.2, 1.1, 9.9 };

	auto db{getValidNumber("Enter a number between 1.0 and 9.9: ", 1.0, 9.9)};

	int index1{findIndex(db, arr1)};

	printArray(arr1);
	
	if(index == -1)
	{
		std::cout << "The number " << db << " was not find.\n";
	}else
	{
		std::cout << "The number " << db << " has index " << index1 << '\n';
	}

	std::cout << findMax(arr) << '\n';

	std::cout << findMax(arr1) << '\n';

	return 0;
}


