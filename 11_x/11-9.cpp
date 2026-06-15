#include <iostream>

template <auto N>
constexpr int factorial()
{
	static_assert(N >= 0, "N must be non-negative");
	int product{1};
	for(int i{1}; i <= N; ++i)
	{
		product *= i;
	}
	return product;
}

int main()
{
	static_assert(factorial<0>() == 1);
	static_assert(factorial<3>() == 6);
	static_assert(factorial<5>() == 120);


	return 0;
}


