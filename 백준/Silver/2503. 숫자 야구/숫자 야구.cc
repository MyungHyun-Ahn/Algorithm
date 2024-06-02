#include <stdio.h>
#include <map>

using namespace std;

map<int, bool> m;

void RemoveNum(int n1, int n2, int n3, int s, int b)
{
	// 숫자 넣기
	int num1[3] = { n1, n2, n3 };

	for (auto &num : m)
	{
		int stCount = 0;
		int ballCount = 0;

		int num2[3] = { num.first / 100, (num.first % 100) / 10, num.first % 10 };

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (x == y && num1[x] == num2[y]) // strike
					++stCount;
				else if (num1[x] == num2[y]) // ball
					++ballCount;
			}
		}

		// 위 조건에 부합하지 않으면 가능성 없는 숫자
		if (stCount != s || ballCount != b)
			m[num.first] = false;
	}
}


int main()
{
	// 전체 경우 등록
	for (int x = 1; x <= 9; x++)
		for (int y = 1; y <= 9; y++)
			for (int z = 1; z <= 9; z++)
			{
				if (x == y || y == z || z == x)
					continue;

				int num = x * 100 + y * 10 + z;
				// 모두 가능한 경우로 체크
				m[num] = true;
			}

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		int num, s, b;
		scanf("%d %d %d", &num, &s, &b);

		RemoveNum(num / 100, (num % 100) / 10, num % 10, s, b);
	}

	int count = 0;
	for (auto &num : m)
	{
		// true만 세기
		if (num.second)
		{
			++count;
		}
	}

	printf("%d", count);
	return 0;
}