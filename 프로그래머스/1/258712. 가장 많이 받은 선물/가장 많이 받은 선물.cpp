#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream> 
#include <vector>
#include <map>

using namespace std;

int g_arrGifts[50][50];
int g_arrGiftScore[50];
int g_arrHowManyGifts[50];

vector<string> split(string input, char delimiter)
{
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		answer.push_back(temp);
	}

	return answer;
};

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;
	int fSize = friends.size();

	map<string, int> fMap;

	for (int i = 0; i < fSize; i++)
	{
		fMap[friends[i]] = i;
	}

	// y 준 사람 x 받은 사람
	for (int i = 0; i < gifts.size(); i++)
	{
		vector<string> vec = split(gifts[i], ' ');

		g_arrGifts[fMap[vec[0]]][fMap[vec[1]]] += 1;
	}

	for (int i = 0; i < fSize; i++)
	{
		g_arrGifts[i][i] = -1;
	}

	// 선물 지수 계산
	for (int i = 0; i < fSize; i++)
	{

		int sum1 = 0;
		// 받은 선물 계산 - x 방향
		for (int j = 0; j < fSize; j++)
		{
			if (g_arrGifts[i][j] == -1)
				continue;

			sum1 += g_arrGifts[i][j];
		}

		int sum2 = 0;
		// 준 선물 계산 - y 방향
		for (int j = 0; j < fSize; j++)
		{
			if (g_arrGifts[j][i] == -1)
				continue;

			sum2 += g_arrGifts[j][i];
		}

		g_arrGiftScore[i] = sum1 - sum2;
	}

	// y 가 준 사람
	for (int y = 0; y < fSize; y++)
	{
		// x 가 받은 사람
		for (int x = 0; x < fSize; x++)
		{
			if (x == y)
				continue;

			// 주고 받은 기록이 없다면 선물지수 비교
            if ((g_arrGifts[y][x] == 0 || g_arrGifts[y][x] == g_arrGifts[x][y]) && g_arrGiftScore[y] < g_arrGiftScore[x])
			{
				g_arrHowManyGifts[x]++;
				continue;
			}

			if (g_arrGifts[y][x] < g_arrGifts[x][y])
			{
				g_arrHowManyGifts[x]++;
			}
		}
	}

	for (int i = 0; i < fSize; i++)
	{
		if (answer < g_arrHowManyGifts[i])
			answer = g_arrHowManyGifts[i];
	}

	return answer;
}