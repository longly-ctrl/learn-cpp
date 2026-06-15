#include <iostream>
#include <string_view>
#include <string>
#include <optional>
#include <utility>

enum class Color
{
	red,
	black,
	blue,
};

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};


template <typename T>
constexpr auto operator+(T a)
{
	return static_cast<std::underlying_type_t<T>>(a);
}

constexpr std::string_view getAnimalName(Animal animal)
{
	using enum Animal;
	switch(animal)
	{
	case pig:
		return "pig";
	case chicken:
		return "chicken";
	case goat:
		return "goat";
	case cat:
		return "cat";
	case dog:
		return "dog";
	case duck:
		return "duck";
	default:
		return "???";
	}
}

void printNumberOfLegs(Animal animal)
{
	using enum Animal;
	std::cout << "A " << getAnimalName(animal) << " has ";
	switch(animal)
	{
	case chicken:
	case duck:
		std::cout << 2;
		break;
	case pig:
	case goat:
	case cat:
	case dog:
		std::cout << 4;
		break;
	default:
		std::cout << "???";
		break;
	}

	std::cout << " legs.\n";
}


constexpr std::string_view getColorName(Color color)
{
	switch(color)
	{
	case Color::red:
		return "red";
	case Color::black:
		return "black";
	case Color::blue:
		return "blue";
	default:
		return "???";
	}
}

constexpr std::optional<Color> getColorFromString(std::string_view sv)
{
	if(sv == "red") return Color::red;
	if(sv == "black") return Color::black;
	if(sv == "blue") return Color::blue;

	return {};
}

std::ostream& operator<<(std::ostream& out, Color color)
{
	out << getColorName(color);
	return out;
}

std::istream& operator>>(std::istream& in, Color& color)
{
	std::string s{};
	in >> s;

	std::optional<Color> match{getColorFromString(s)};

	if(match)
	{
		color = *match;
		return in;
	}

	in.setstate(std::ios_base::failbit);

	return in;
}


int main()
{
	std::cout << "Enter what color your pet are?";

	Color color;
	std::cin >> color;
	
	std::cout << "number: ";
	int input;
	std::cin >> input;
	Color shift{ Color::blue };

	Color color1 {static_cast<Color>(input)};
	std::cout << color1 << '\n';
	std::cout << +Color::blue << '\n';
	std::cout << shift << '\n';
	std::cout << color << '\n';
	std::cout << std::to_underlying(color) << '\n';

	printNumberOfLegs(Animal::cat);
	printNumberOfLegs(Animal::chicken);



	return 0;
}
