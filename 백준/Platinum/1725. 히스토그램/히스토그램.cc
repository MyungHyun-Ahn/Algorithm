#include <stdio.h>
#include <stack>

int g_iArrHeight[100004];
int g_iMax = 0;

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &g_iArrHeight[i]);
	}

	long long space = 0;

	std::stack<int> st;
	st.push(0);

	for (int i = 1; i <= N + 1; i++)
	{
		while (!st.empty() && g_iArrHeight[st.top()] > g_iArrHeight[i])
		{
			int t = st.top();
			st.pop();

			space = (i - st.top() - 1) * g_iArrHeight[t];
			g_iMax = g_iMax < space ? space : g_iMax;
		}

		st.push(i);
	}

	printf("%d", g_iMax);

	return 0;
}