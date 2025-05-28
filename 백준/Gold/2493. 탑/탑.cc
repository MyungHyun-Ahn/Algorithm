#include <stdio.h>
#include <vector>

int arrTops[500000];
int result[500000] = { 0, };

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int top;
		scanf("%d", &top);
		arrTops[i] = top;
	}

	std::vector<std::pair<int, int>> stack;
	stack.push_back(std::make_pair(n - 1, arrTops[n - 1]));
	for (int i = n - 2; i >= 0; i--)
	{
		while (!stack.empty() && stack.back().second < arrTops[i])
		{
			result[stack.back().first] = i + 1;
			stack.pop_back();
		}

		stack.push_back(std::make_pair(i, arrTops[i]));
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("%d ", result[i]);
	}

	return 0;
}