#include <stdio.h>
#include <string.h>
#include <algorithm>

/*
두가지 함수
R 뒤집기 - 배열에 있는 수의 순서를 뒤집음

D 버리기 - 첫 번째 수를 버림
	     - 배열이 비었을 때 사용하면 에러


*/

char func[100000];
char chArr[1000000];
int iArr[100000];

int isReverse = 0;
int startIdx = 0;
int endIdx = 0;

// 뒤집기
void R()
{
	isReverse = ~isReverse;
}

// 버리기
bool D()
{
	if (startIdx > endIdx)
		return false;

	if (isReverse)
		endIdx--;
	else
		startIdx++;

	return true;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%s", func);

		int n;
		scanf("%d", &n);
		scanf("%s", chArr);

		const char *sep = "[,]";
		char * nextTok = strtok(chArr, sep);

		int numCount = 0;
		while (nextTok != nullptr)
		{
			iArr[numCount++] = atoi(nextTok);
			nextTok = strtok(nullptr, sep);
		}

		startIdx = 0;
		endIdx = numCount - 1;

		for (int i = 0; func[i] != '\0'; i++)
		{
			switch (func[i])
			{
			case 'R':
				R();
				break;

			case 'D':
			{
				bool isSuccess = D();
				if (!isSuccess)
				{
					printf("error\n");
					goto END;
				}
			}
				break;
			}
		}

		printf("[");
		if (isReverse)
		{
			for (int i = endIdx; i >= startIdx; i--)
			{
				printf("%d", iArr[i]);
				if (i != startIdx)
					printf(",");
			}
		}
		else
		{
			for (int i = startIdx; i <= endIdx; i++)
			{
				printf("%d", iArr[i]);
				if (i != endIdx)
					printf(",");
			}
		}

		printf("]\n");

	END:
		isReverse = 0;
	}
}