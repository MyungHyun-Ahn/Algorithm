#include <iostream>
#include <vector>
#include <string>

int main()
{
	int n;
	std::cin >> n;

	std::string str; 
	std::cin >> str;

	std::vector<int> values(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> values[i];
	}

	std::vector<double> vec;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			vec.push_back(values[str[i] - 'A']);
		}
		else
		{
			if (!vec.empty())
			{
				double temp = vec.back();
				vec.pop_back();
				switch (str[i])
				{
				case '+':
					temp = vec.back() + temp;
					break;
				case '-':
					temp = vec.back() - temp;
					break;
				case '*':
					temp = vec.back() * temp;
					break;
				case '/':
					temp = vec.back() / temp;
					break;
				}
				vec.pop_back();
				vec.push_back(temp);
			}
		}
	}

	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << vec.back() << '\n';
}