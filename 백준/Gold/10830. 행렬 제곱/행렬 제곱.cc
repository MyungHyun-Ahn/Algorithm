#include <stdio.h>

#define MAX_N 5

int n;

struct Matrix
{
	int matrix[MAX_N][MAX_N] = { 0, };

	Matrix operator*(const Matrix &other) const
	{
		Matrix newMat;
		for (int y = 0; y < n; ++y)
			for (int x = 0; x < n; ++x)
			{
				newMat.matrix[y][x] = 0;

				for (int a = 0; a < n; ++a)
					newMat.matrix[y][x] += (this->matrix[y][a] * other.matrix[a][x]);

				newMat.matrix[y][x] %= 1000;
			}

		return newMat;
	}
};

Matrix g_identity;

Matrix pow(Matrix a, long long n)
{
	if (n == 0)
		return g_identity;

	// 짝수
	if (n % 2 > 0)
		return pow(a, n - 1) * a;		

	Matrix half = pow(a, n / 2);
	return half * half;
}

int main()
{
	long long b;

	scanf("%d %lld", &n, &b);

	for (int i = 0; i < n; ++i)
	{
		g_identity.matrix[i][i] = 1;
	}


	Matrix matrix;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			scanf("%d", &matrix.matrix[y][x]);
		}
	}

	Matrix mat = pow(matrix, b);

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			printf("%d ", mat.matrix[y][x] % 1000);
		}
		printf("\n");
	}

	return 0;
}