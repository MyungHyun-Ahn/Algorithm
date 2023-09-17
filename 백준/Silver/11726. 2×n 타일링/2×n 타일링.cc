#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	/*
	0 1 2 3 4 5 6  7 8 9 10
	0 1 2 3 5 8 13 21 34 55
	*/

	std::vector<int> vec(n + 1);

	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 2;

	for (int i = 3; i < n + 1; ++i)
	{
		vec[i] = (vec[i - 2] + vec[i - 1]) % 10007;
	}

	std::cout << vec[n];
}