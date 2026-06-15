#include <iostream>

template <typename T>
struct Triad
{
	T i1;
	T i2;
	T i3;
};
template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
constexpr void print(Triad<T> t)
{
	std::cout<< "[" << t.i1 << ", " << t.i2 << ", " << t.i3 << "]";
}

int main()
{
	Triad t1{ 1, 2, 3 };
	print(t1);
	Triad t2{ 1.2, 3.4, 5.6 };
	print(t2);

	return 0;
}

