#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> strVec;
std::string answer;

void QTree(int sX, int dX, int sY, int dY)
{
	char firstCh = strVec[sY][sX];

	if (sX == dX && sY == dY)
		goto T;

	// 체크
	for (int y = sY; y < dY; ++y)
	{
		for (int x = sX; x < dX; ++x)
		{
			if (firstCh != strVec[y][x])
				goto F;
		}
	}


T:
	if (firstCh == '0')
		answer += "0";
	else
		answer += "1";

	return;

F:
	int half = (dX - sX) / 2;

	answer += '(';

	QTree(sX, sX + half, sY, sY + half);

	QTree(sX + half, dX, sY, sY + half);

	QTree(sX, sX + half, sY + half, dY);

	QTree(sX + half, dX, sY + half, dY);

	answer += ')';
}

int main()
{
	int N;
	std::cin >> N;

	for (int y = 0; y < N; ++y)
	{
		std::string str;
		std::cin >> str;
		strVec.push_back(str);
	}

	QTree(0, N, 0, N);

	std::cout << answer << std::endl;

	return 0;
}