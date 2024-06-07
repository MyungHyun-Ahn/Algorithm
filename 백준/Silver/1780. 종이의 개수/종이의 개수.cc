#include <stdio.h>
#include <vector>

int N;
std::vector<int> matrix;

int minusOne = 0;
int zero = 0;
int one = 0;

void Divide(int sX, int dX, int sY, int dY)
{
	int firstNum = matrix[sX + N * sY];

	if (sX == dX)
		goto T;

	for (int y = sY; y < dY; ++y)
	{
		for (int x = sX; x < dX; ++x)
		{
			if (firstNum != matrix[x + N * y])
				goto F;
		}
	}


T:
	if (firstNum == -1)
		++minusOne;
	else if (firstNum == 0)
		++zero;
	else
		++one;

	return;
F:

	int trisect = (dX - sX) / 3;
	Divide(sX, sX + trisect, sY, sY + trisect);
	Divide(sX + trisect, sX + trisect * 2, sY, sY + trisect);
	Divide(sX + trisect * 2, dX, sY, sY + trisect);
	Divide(sX, sX + trisect, sY + trisect, sY + trisect * 2);
	Divide(sX + trisect, sX + trisect * 2, sY + trisect, sY + trisect * 2);
	Divide(sX + trisect * 2, dX, sY + trisect, sY + trisect * 2);
	Divide(sX, sX + trisect, sY + trisect * 2, dY);
	Divide(sX + trisect, sX + trisect * 2, sY + trisect * 2, dY);
	Divide(sX + trisect * 2, dX, sY + trisect * 2, dY);
}

int main()
{
	scanf("%d", &N);

	matrix.reserve(N * N);

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			int num;
			scanf("%d", &num);
			matrix[x + N * y] = num;
		}
	}

	Divide(0, N, 0, N);

	printf("%d\n%d\n%d\n", minusOne, zero, one);

	return 0;
}