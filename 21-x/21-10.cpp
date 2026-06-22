#include <iostream>
#include <string>
#include <string_view>
#include <cassert>

class MyString
{
private:
	std::string m_s{};

public:
	MyString(std::string_view s = {})
		:m_s{s}
	{}
	friend std::ostream& operator<<(std::ostream& out, const MyString& s)
	{
		out << s.m_s;
		return out;
	}

	MyString operator()(int start, int length)
	{
		assert(start >= 0);
		assert(start + length <= static_cast<int>(m_s.length()) &&
				"MyString::operator(int, int): Substring is out of range");

	return MyString {m_s.substr(static_cast<std::size_t>(start), static_cast<std::size_t>(length))};
	}

};

int main()
{
	MyString s{"Hello, world!"};
	std::cout << s(7, 5) << '\n';
}


