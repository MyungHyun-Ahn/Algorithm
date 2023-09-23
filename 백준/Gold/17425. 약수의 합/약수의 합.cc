#include <stdio.h>

#define MAX 1000001

using namespace std;

long long ret[MAX + 1];

int main()
{

	// 미리 값 계산하기
	// A = B * C 성질 이용
	// i 번째 숫자로 나누어지는 경우 더하기 i 번 숫자부터 * n 배의 숫자는 모두 나누어지는 것
	// j = i 부터 -> MAX 까지
	// i 번의 계산이 끝난 이후 [i - 1] 의 값을 더해주기 약수의 합 계산
	for (int i = 1; i <= MAX; ++i)
	{
		for (int j = i; j <= MAX; j += i)
		{
			ret[j] += i;
		}
		ret[i] += ret[i - 1];
	}

	int t, num;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i)
	{
		scanf("%d", &num);
		
		printf("%lld\n", ret[num]);
	}
}