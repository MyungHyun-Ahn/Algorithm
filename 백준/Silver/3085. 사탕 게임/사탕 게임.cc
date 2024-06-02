#include <iostream>
#include <string>
#include <vector>

int N;
std::vector<std::string> candyMap;

// 세로 가로줄 중 가장 큰 수를 반환
int CountCandy()
{
	int maxVal = 0;

	// 가로줄 순회
	for (int y = 0; y < N; ++y)
	{
		int count = 1;
		for (int x = 1; x < N; ++x)
		{
			if (candyMap[y][x] == candyMap[y][x - 1])
				++count;
			else
				count = 1;

			// count 비교하여 갱신
			maxVal = maxVal < count ? count : maxVal;
		}
	}

	// 세로줄 순회
	for (int x = 0; x < N; ++x)
	{
		int count = 1;
		for (int y = 1; y < N; ++y)
		{
			if (candyMap[y][x] == candyMap[y - 1][x])
				++count;
			else
				count = 1;

			// count 비교하여 갱신
			maxVal = maxVal < count ? count : maxVal;
		}
	}

	return maxVal;
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;
		candyMap.push_back(str);
	}

	int maxCount = 0;

	// 인덱스 순회
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			// 첫 인덱스 x, y

			int count = 0;

			// 위 y - 1이 0보다 크면 진행 가능
			if (y - 1 >= 0 && candyMap[y][x] != candyMap[y - 1][x])
			{
				// 바꾸기
				std::swap(candyMap[y][x], candyMap[y - 1][x]);

				// 개수 세기
				count = CountCandy();
				maxCount = maxCount < count ? count : maxCount;

				// 다시 되돌리기
				std::swap(candyMap[y][x], candyMap[y - 1][x]);

			}

			// 아래
			if (y + 1 < 0 && candyMap[y][x] != candyMap[y + 1][x])
			{
				// 바꾸기
				std::swap(candyMap[y][x], candyMap[y + 1][x]);

				// 개수 세기
				count = CountCandy();
				maxCount = maxCount < count ? count : maxCount;

				// 다시 되돌리기
				std::swap(candyMap[y][x], candyMap[y + 1][x]);
			}


			// 왼
			if (x - 1 >= 0 && candyMap[y][x] != candyMap[y][x - 1])
			{
				// 바꾸기
				std::swap(candyMap[y][x], candyMap[y][x - 1]);

				// 개수 세기
				count = CountCandy();
				maxCount = maxCount < count ? count : maxCount;

				// 다시 되돌리기
				std::swap(candyMap[y][x], candyMap[y][x - 1]);
			}

			// 오른
			if (x + 1 >= 0 && candyMap[y][x] != candyMap[y][x + 1])
			{
				// 바꾸기
				std::swap(candyMap[y][x], candyMap[y][x + 1]);

				// 개수 세기
				count = CountCandy();
				maxCount = maxCount < count ? count : maxCount;

				// 다시 되돌리기
				std::swap(candyMap[y][x], candyMap[y][x + 1]);
			}
		}
	}

	std::cout << maxCount;

	return 0;
}