#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int map[101][101] = { 0 };

	for (int i = 0; i < puddles.size(); i++)
	{
		// 물웅덩이 -1 채우기
		map[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
	}


	for (int y = 0; y < n; y++) { // i : 행
		for (int x = 0; x < m; x++) { // j : 열            
			if (map[y][x] == -1) {
				map[y][x] = 0;
				continue;
			}
			if (x == 0 && y == 0) {
				map[y][x] = 1;
				continue;
			}
			if (y == 0) {
				map[y][x] = map[y][x - 1];
				continue;
			}
			if (x == 0) {
				map[y][x] = map[y - 1][x];
				continue;
			}
			map[y][x] = map[y - 1][x] + map[y][x - 1];
			map[y][x] %= 1000000007;

		}
	}
	
	
	int answer = map[n - 1][m - 1];
	return answer;
}