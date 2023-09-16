#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
	std::list<std::string> s;
	std::string str;

	while (std::getline(std::cin, str))
	{
		if (!str.length())
			break;
		s.push_back(str);
	}

	std::vector<std::vector<int>> ret;

	while (!s.empty())
	{
		std::string str1 = s.front();
		s.pop_front();

		std::vector<int> li(4, 0);
		for (auto c : str1)
		{
			if ('a' <= c && c <= 'z')
			{
				++li[0];
			}
			else if ('A' <= c && c <= 'Z')
			{
				++li[1];
			}
			else if ('0' <= c && c <= '9')
			{
				++li[2];
			}
			else if (c == ' ')
			{
				++li[3];
			}
		}

		ret.push_back(li);
	}

	for (auto li : ret)
	{
		for (auto l : li)
		{
			std::cout << l << " ";
		}

		std::cout << std::endl;
	}
}