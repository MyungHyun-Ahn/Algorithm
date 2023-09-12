#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string str;
	getline(std::cin, str);



	std::vector<char> vec;
	std::vector<char> print;


	bool isBlock = false;
	for (int i = 0; i < str.length(); ++i)
	{
		// < 를 만나면 뒤집기 중지
		if (str[i] == '<')
		{
			isBlock = true;
			while (!vec.empty())
			{
				print.push_back(vec.back());
				vec.pop_back();
			}
		}

		// 블록 상태가 아닐 때 띄워쓰기를 만나면
		if (str[i] == ' ' && !isBlock)
		{
			while (!vec.empty())
			{
				print.push_back(vec.back());
				vec.pop_back();
			}
		}
		// 블록 상태가 아니고 띄워쓰기도 아닐 때
		else if (!isBlock)
		{
			vec.push_back(str[i]);
			continue;
		}

		// > 를 만나면 뒤집기 다시 시작
		if (str[i] == '>')
		{
			isBlock = false;
		}

		print.push_back(str[i]);
	}

	// 마지막 벡터에 남은게 있다면
	while (!vec.empty())
	{
		print.push_back(vec.back());
		vec.pop_back();
	}
	
	for (int i = 0; i < print.size(); ++i)
	{
		if (print[i] == ' ')
			std::cout << ' ';
		else
			std::cout << print[i];
	}

	std::cout << std::endl;


	return 0;
}