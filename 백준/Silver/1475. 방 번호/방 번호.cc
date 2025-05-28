
#include <stdio.h>

int main()
{
	char n[10];
	scanf("%s", n);

	int arrNum[9] = { 0, };
	for (int i = 0; n[i] != '\0'; i++)
	{
		int numIndex = n[i] - '0';
		if (numIndex == 9)
			numIndex = 6;
		arrNum[numIndex]++;
	}
	 
	int flag = 0;
	if (arrNum[6] % 2 == 1)
		flag = 1;

	arrNum[6] /= 2;
	if (flag)
		arrNum[6] += 1;

	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		if (max < arrNum[i])
			max = arrNum[i];
	}

	printf("%d", max);

	return 0;
}