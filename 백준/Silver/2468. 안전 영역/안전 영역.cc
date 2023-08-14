#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int cnt;

vector<vector<int>> v;
vector<vector<bool>> discovered;
vector<vector<int>> nextPos;

void solution(int x, int y, int water)
{
	if (v[y][x] <= water)
		return;


	queue<vector<int>> q;
	
	// n보다 높고 해당 함수에서 처음 발견된 경우에만 count 증가
	if (discovered[y][x] == false)
	{
		cnt++;
	}

	q.push({ y, x });
	discovered[y][x] = true;

	while (q.empty() == false)
	{
		vector<int> nowPos = q.front();
		q.pop();

		// 상하좌우로 이동
		for (vector<int> next : nextPos)
		{
			int nextY = nowPos[0] + next[0];
			int nextX = nowPos[1] + next[1];

			// 범위 체크
			if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n)
				continue;

			// 이미 발견했거나 n 보다 작으면 패스
			if (discovered[nextY][nextX] == true || v[nextY][nextX] <= water)
				continue;

			// 여기까지 왔으면 조건 충족
			q.push({ nextY, nextX });
			discovered[nextY][nextX] = true;
		}
	}
}

int main()
{
	int maxCnt = 0;

	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	nextPos = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			v[i][j] = num;
		}
	}

	for (int water = 0; water < 100; water++)
	{
		cnt = 0;
		discovered = vector<vector<bool>>(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				solution(i, j, water);
			}
		}
		if (cnt > maxCnt)
			maxCnt = cnt;
	}

	cout << maxCnt << endl;
}