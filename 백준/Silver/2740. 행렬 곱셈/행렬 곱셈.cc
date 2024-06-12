#include <stdio.h>

int matrixA[100][100];
int matrixB[100][100];
int answer[100][100] = { 0, };


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < m; ++x)
		{
			scanf("%d", &matrixA[y][x]);
		}
	}

	int m2, k;
	scanf("%d %d", &m2, &k);

	for (int y = 0; y < m2; ++y)
	{
		for (int x = 0; x < k; ++x)
		{
			scanf("%d", &matrixB[y][x]);
		}
	}

	// 행렬 곱셈
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < k; ++x)
		{
			for (int a = 0; a < m; ++a)
			{
				answer[y][x] += (matrixA[y][a] * matrixB[a][x]);
			}

			printf("%d ", answer[y][x]);
		}

		printf("\n");
	}

	return 0;
}