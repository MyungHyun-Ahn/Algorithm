#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	/*
	0 1 2 3 4 5 6 7 8 9 10
	0 0 1 1 2 3 3 4 3 2 3
	*/

	std::vector<int> vec(n + 1);

	vec[0] = 0;
	vec[1] = 0;

	for (int i = 2; i < n + 1; ++i)
	{
		vec[i] = vec[i - 1] + 1;

		if (i % 3 == 0)
			vec[i] = std::min(vec[i], vec[i / 3] + 1);

		if (i % 2 == 0)
			vec[i] = std::min(vec[i], vec[i / 2] + 1);
	}
	
	std::cout << vec[n];
}