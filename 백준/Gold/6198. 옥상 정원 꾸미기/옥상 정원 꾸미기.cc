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
	stack.push_back(std::make_pair(0, arrTops[0]));
	for (int i = 1; i < n; i++)
	{
		while (!stack.empty() && stack.back().second <= arrTops[i])
		{
			result[stack.back().first] = i - stack.back().first - 1;
			stack.pop_back();
		}

		stack.push_back(std::make_pair(i, arrTops[i]));
	}
	
	// 남아있는 것 처리 - 여기부턴 뒤에 있는 모든 옥상을 확인 가능
	while (!stack.empty())
	{
		if (stack.back().first != n - 1)
		{
			result[stack.back().first] = n - stack.back().first - 1;
		}

		stack.pop_back();
	}

	unsigned int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += result[i];
	}

	printf("%lld", sum);

	return 0;
}