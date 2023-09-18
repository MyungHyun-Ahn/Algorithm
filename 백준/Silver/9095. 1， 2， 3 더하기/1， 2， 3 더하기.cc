#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	/*
	0 1 2 3 4 5 6 7 8 9 10 11
	0 1 2 4 7 13
	*/

	std::vector<int> vec(4);

	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 4;

	int idx = 4;
	for (int i = 0; i < n; ++i)
	{
		int val;
		std::cin >> val;

		for (idx; idx < val + 1; ++idx)
		{
			vec.push_back(vec[idx - 3] + vec[idx - 2] + vec[idx - 1]);
		}

		std::cout << vec[val] << std::endl;;
	}
}