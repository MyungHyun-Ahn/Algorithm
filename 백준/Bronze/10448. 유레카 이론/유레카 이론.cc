#include <stdio.h>
#include <vector>

using namespace std;

bool g_isSucc = false;
void triangularNumber(int num, int n, int numCount)
{
	if (n == 0)
	{
		// 1부터 재귀함수 쫘르륵 호출
		for (int i = 1; i <= 46; ++i)
		{
			triangularNumber(num, i, numCount);
		}
        
        return;
	}

	// 기저 조건
	// 1. 숫자 3개 이상 사용한 경우 실패
	if (numCount > 2)
		return;

	// 2. num - Tn이 0보다 작아지면 실패
	int tn = n * (n + 1) / 2;
	int nextNum = num - tn;
	if (nextNum < 0)
		return;

	// 3. num - Tn 이 0이면 성공
	if (nextNum == 0)
	{
		if (numCount != 2)
			return;

		g_isSucc = true;
		return;
	}

	// 여기부터는 진행해도 괜찮은 상황 Tn이 0 보다 큰 경우
	// 작은 수부터 진행
	// K가 1000까지 이므로 n은 46까지 진행해도 괜찮음
	for (int i = n; i <= 46; ++i)
	{
		triangularNumber(nextNum, i, numCount + 1);
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	vector<int> vec;

	for (int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d", &n);
		vec.push_back(n);
	}

	// 완전 탐색 진행
	for (int i = 0; i < t; ++i)
	{
		g_isSucc = false;
		triangularNumber(vec[i], 0, 0);
		printf("%d\n", g_isSucc);
	}

	return 0;
}