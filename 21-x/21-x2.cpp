#include <iostream>
#include <cassert>

class IntArray
{
private:
	int m_length{0};
	int* m_array{ nullptr };

public:
	explicit IntArray(int length)
			:m_length {length}
	{
		assert(m_length > 0 && "IntArray length should be a possitive integer");
		m_array = new int[static_cast<std::size_t>(m_length)] {};
	}

	IntArray(const IntArray& array)
		:m_length{array.m_length}
	{

		m_array = new int[static_cast<std::size_t>(m_length)] {};

		for(int count{0}; count < m_length; ++count)
			m_array[count] = array.m_array[count];
	}

	~IntArray()
	{
		delete[] m_array;
	}

	friend std::ostream& operator<<(std::ostream& out, const IntArray& array)
	{
		for(int i{0}; i < array.m_length; ++i)
		{
			std::cout << array.m_array[i] << ' ';
		}

		return out;
	}

	int& operator[](const int i)
	{
		assert(i >= 0);
		assert(i < m_length);
		return m_array[i];
	}

	IntArray& operator=(const IntArray& array)
	{
		if(this == &array)
			return *this;
		delete[] m_array;

		m_length = array.m_length;
		m_array = new int[static_cast<std::size_t>(m_length)] {};

		for(int i{0}; i < m_length; ++i)
		{
			m_array[i] = array.m_array[i];
		}

		return *this;
	}
};

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
	return a;
}

int main()
{
	IntArray a {fillArray()};

	std::cout << a << '\n';

	auto& ref {a};
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';
	std::cout << a << '\n';

	return 0;
}
