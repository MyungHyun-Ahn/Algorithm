#include <stdio.h>
#include <vector>

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> inputVec;
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		inputVec.push_back(num);
	}

	std::vector<char> outputVec;
	std::vector<int> stack;
	int current = 1;
	stack.push_back(current++);
	outputVec.push_back('+');
	bool flag = false;
	for (int num : inputVec)
	{
		for (;;)
		{
			if (stack.empty() || num > stack.back())
			{
				outputVec.push_back('+');
				stack.push_back(current++);
			}

			if (num == stack.back())
			{
				outputVec.push_back('-');
				stack.pop_back();
				break;
			}

			if (num < stack.back())
			{
				// NO
				flag = true;
				break;
			}

		}

		if (flag)
			break;
	}

	if (flag)
	{
		printf("NO\n");
	}
	else
	{
		for (char out : outputVec)
		{
			printf("%c\n", out);
		}
	}

	return 0;
}