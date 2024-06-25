#include <stdio.h>
#include <algorithm>

// 제곱수의 합

// 제곱수들 체크
// [i] = min([i], [i - j * j] + [j * j])
// [j * j] = 1

int arrCnt[100001];

int main()
{
	int N;
	scanf("%d", &N);

	arrCnt[0] = 0;
	arrCnt[1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		arrCnt[i] = i;

		for (int j = 1; j * j <= i; ++j)
		{
			arrCnt[i] = std::min(arrCnt[i], 1 + arrCnt[i - j * j]);
		}
	}

	printf("%d", arrCnt[N]);

	return 0;
}