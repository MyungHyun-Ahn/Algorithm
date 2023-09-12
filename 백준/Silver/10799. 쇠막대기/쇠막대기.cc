#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string str;
	getline(std::cin, str);

	std::vector<char> vec;
	std::vector<int> lasorCounts;


	int count = 0;
	bool islaser = true;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(')
		{
			islaser = true; // 처음 push 에서 레이저 체크
			vec.push_back(str[i]);
			lasorCounts.push_back(0);
			continue;
		}

		// 벡터가 비면 0으로 초기화
		if (vec.empty())
		{
			continue;
		}


		// true 면 laser
		if (str[i] == ')' && vec.back() == '(' && islaser)
		{
			islaser = false;
			vec.pop_back();
			lasorCounts.pop_back();
			for (int j = 0; j < vec.size(); ++j)
			{
				lasorCounts[j] += 1;
			}
			continue;
		}

		if (str[i] == ')' && vec.back() == '(' && !islaser)
		{
			count += lasorCounts.back() + 1;
			vec.pop_back();
			lasorCounts.pop_back();
		}
	}

	std::cout << count << std::endl;

	return 0;
}