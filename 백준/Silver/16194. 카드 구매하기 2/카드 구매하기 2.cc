#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;


	std::vector<int> vec(n + 1, 0);
	for (int i = 1; i < n + 1; ++i)
	{
		int val;
		std::cin >> val;

		vec[i] = val;
	}

	std::vector<int> res(n + 1, INT32_MAX - 1);
	res[0] = vec[0];
	res[1] = vec[1];

	for (int i = 2; i < n + 1; ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			res[i] = std::min(res[i], res[i - j] + vec[j]);
		}
	}

	std::cout << res[n] << std::endl;
}