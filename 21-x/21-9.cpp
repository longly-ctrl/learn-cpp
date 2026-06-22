#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>

struct StudentGrade
{
	std::string name{};
	char grade{};
};

class GradeMap
{
private:
	std::vector<StudentGrade> m_map{};

public:
	char& operator[](std::string_view s)
	{
		auto found{std::find_if(m_map.begin(), m_map.end(), 
				[s](const auto& student)
				{
					return (student.name == s);
				})};
		if(found != m_map.end())
		{
			return found->grade;
		}

		return m_map.emplace_back(std::string{s}).grade;
	}




};

int main()
{
	GradeMap grades{};
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
