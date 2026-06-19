#include <iostream>
#include <array>
#include <string_view>
#include <string>
#include <limits>

namespace Animal
{
	enum Type
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals
	};

	struct Data
	{
		std::string_view name{};
		int legs{};
		std::string_view sound{};
	};

	constexpr std::array types{ chicken, dog, cat, elephant, duck, snake };
	constexpr std::array data{Data{"chicken", 2, "cluck"}, Data{"dog", 4, "woof"}, Data{"cat", 4, "meow"},
		Data{"elephant", 4, "pawoo"}, Data{"duck", 2, "quack"}, Data{"snake", 0, "hissss"}};
	static_assert(std::size(types) == max_animals);
	static_assert(std::size(data) == max_animals);
}

constexpr std::string_view getAnimalName(Animal::Type type)
{
	return Animal::data[static_cast<std::size_t>(type)].name;
}

std::ostream& operator<<(std::ostream& out, Animal::Type type)
{
	return out << getAnimalName(type);
}

std::istream& operator>>(std::istream& in, Animal::Type& animal)
{
	std::string input{};
	std::getline(in >> std::ws, input);

	for(std::size_t index{0}; index < Animal::data.size(); ++index)
	{
		if(input == Animal::data[index].name)
		{
			animal = static_cast<Animal::Type>(index);
			return in;
		}

	}
	in.setstate(std::ios_base::failbit);
	return in;
}


void printAnimalData(Animal::Type type)
{
	const Animal::Data& animal {Animal::data[type]};
	std::cout << "A " << animal.name << " has " <<
		animal.legs << " legs and says " << animal.sound << '\n';
}


int main()
{
	std::cout << "Enter an animal: ";
	Animal::Type input{};
	std::cin >> input;

	if(!std::cin)
	{
		std::cin.clear();
		std::cout << "That animal couldn't be found.\n";
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		input = Animal::max_animals;
	}
	else
	{
		printAnimalData(input);
	}

	std::cout << "\nHere is the data for the rest of the animals:\n";
	for(auto a : Animal::types)
	{
		if(a != input)
			printAnimalData(a);
	}
	return 0;
}



