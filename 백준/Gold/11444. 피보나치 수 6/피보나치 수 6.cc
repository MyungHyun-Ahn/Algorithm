#include <stdio.h>
#define MAX_N 2
struct Matrix
{
	long long matrix[MAX_N][MAX_N] = { 0, };

	Matrix operator*(const Matrix &other) const
	{
		Matrix newMat;
		for (int y = 0; y < 2; ++y)
			for (int x = 0; x < 2; ++x)
			{
				newMat.matrix[y][x] = 0;

				for (int a = 0; a < 2; ++a)
					newMat.matrix[y][x] += (this->matrix[y][a] * other.matrix[a][x]);

				newMat.matrix[y][x] %= 1000000007;
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
	long long n;
	scanf("%lld", &n);

	for (int i = 0; i < 2; ++i)
	{
		g_identity.matrix[i][i] = 1;
	}

	Matrix mat;
	mat.matrix[0][0] = 1;
	mat.matrix[0][1] = 1;
	mat.matrix[1][0] = 1;
	mat.matrix[1][1] = 0;

	Matrix m = pow(mat, n - 1);
	
	long long answer = m.matrix[0][0];
	printf("%lld", answer);

	return 0;
}