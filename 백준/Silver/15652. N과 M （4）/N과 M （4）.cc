#include <stdio.h>
#include <vector>

// N과 M
// 1 ~ 8
int arrNum[9];

// 1부터 N까지 자연수 중 중복 없이 M개를 고른 수열
int g_SelCount;
int g_MaxN;

void backtracking(int N, int M)
{
	// M 번째에 N 등록
	arrNum[M] = N;

	if (M == g_SelCount)
	{
		for (int i = 1; i <= M; i++)
		{
			printf("%d ", arrNum[i]);
		}
		printf("\n");
		return;
	}

	// N + 1을 M + 1번으로 고를 것임
	for (int i = N; i <= g_MaxN; i++)
	{
		backtracking(i, M + 1);
	}
}

void solution(int N, int M)
{
	g_SelCount = M;
	g_MaxN = N;

	// 1 ~ N, M개
	// 백트래킹
	for (int i = 1; i <= N; i++)
	{
		// 1개 고름
		backtracking(i, 1);
	}

}


int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	solution(N, M);
	return 0;
}