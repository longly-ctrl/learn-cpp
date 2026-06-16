#include <iostream>
#include <vector>

void printStackValues(const std::vector<int>& v)
{
	std::cout << "\t(Stack:";

	for(auto e : v)
		std::cout << ' ' << e;

	if(v.empty())
		std::cout << " empty.";

	std::cout << ")\n";
}

void pushAndPrint(int val, std::vector<int>& v)
{
	v.push_back(val);
	std::cout << "Push " << val;
	printStackValues(v);
}

void popAndPrint(std::vector<int>& v)
{
	v.pop_back();
	std::cout << "Pop ";
	printStackValues(v);
}


int main()
{
	std::vector<int> stack{};

	printStackValues(stack);

	pushAndPrint(1, stack);
	pushAndPrint(2, stack);
	pushAndPrint(3, stack);
	popAndPrint(stack);
	pushAndPrint(4, stack);
	popAndPrint(stack);
	popAndPrint(stack);
	popAndPrint(stack);

	return 0;
}
