#include <stdio.h>

// 표 그려서 점화식 찾으면 됨
// F(N, K) = F(N - 1, K - 1) + F(N - 2, K - 1) + ... + F(1, K - 1)

int arrDP[201][201];

int main()
{
	for (int i = 0; i < 201; ++i)
	{
		arrDP[i][1] = 1;
		arrDP[0][i] = 1;
	}

	int N;
	int K;
	scanf("%d %d", &N, &K);

	for (int n = 1; n <= N; ++n)
	{
		for (int k = 2; k <= K; ++k)
		{
			for (int s = 0; s <= n; ++s)
			{
				arrDP[n][k] += arrDP[s][k - 1];
				arrDP[n][k] %= 1000000000;
			}
		}
	}

	printf("%d", arrDP[N][K]);

	return 0;
}