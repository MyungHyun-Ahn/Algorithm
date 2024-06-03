#include <cstdio>

int arrPaper[128][128];

int white = 0;
int blue = 0;

void QuadTree(int sY, int dY, int sX, int dX)
{
	int first = arrPaper[sY][sX];

	// 더 이상 쪼갤 수 없을 때
	if (dY - sY == 0)
		goto T;

	// 모든 영역이 0 혹은 1 인지 검사
	for (int y = sY; y < dY; ++y)
	{
		for (int x = sX; x < dX; ++x)
		{
			if (first != arrPaper[y][x])
				goto F;
		}
	}

T:

	// 여기까지 왔으면 모든 영역이 같은 색인 상황 - 분할하지 않아도 됨
	if (first) // true면 blue
		++blue;
	else
		++white;
	
	return;

F:	// 더 분할 진행
	// 분할
	int half = (dY - sY) / 2;

	QuadTree(sY, sY + half, sX, sX + half);
	QuadTree(sY + half, dY, sX, sX + half);
	QuadTree(sY, sY + half, sX + half, dX);
	QuadTree(sY + half, dY, sX + half, dX);
}


int main()
{
	int N;
	scanf("%d", &N);

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			int num;
			scanf("%d", &num);

			arrPaper[y][x] = num;
		}
	}

	QuadTree(0, N, 0, N);

	printf("%d\n%d", white, blue);

	return 0;
}