#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int DP[501][501] = { 0 };


	// 0 번 칸에 triangle[0][0] 기입
	DP[0][0] = triangle[0][0];

	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
			{
				DP[i][j] = DP[i - 1][j / 2] + triangle[i][j];
				continue;
			}

			if (j == triangle[i].size() - 1)
			{
				DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
				continue;
			}

			DP[i][j] = DP[i - 1][j] + triangle[i][j] > DP[i - 1][j - 1] + triangle[i][j] ? DP[i - 1][j] + triangle[i][j] : DP[i - 1][j - 1] + triangle[i][j];
			
		}
	}

	for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
	{
		answer = answer > DP[triangle.size() - 1][i] ? answer : DP[triangle.size() - 1][i];
	}

	return answer;
}