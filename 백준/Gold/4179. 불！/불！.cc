#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stdlib.h>

#define MAX 1000

/*
언제 불 붙었는지 기록하고
지훈이가 가려하는 시점이 불 붙은 것보다 빠르면 step
*/

using namespace std;

short fireStep[MAX][MAX];

struct Pos
{
	int m_y;
	int m_x;

public:
	Pos() = default;
	Pos(int y_, int x_) : m_y(y_), m_x(x_) {}
	// Pos(short y_, short x_, short step_) : m_y(y_), m_x(x_), step(step_) {}

	void operator=(Pos pos_) 
	{ 
		m_y = pos_.m_y;
		m_x = pos_.m_x;
		// step = pos_.step;
	}
};

int main()
{
	int inX, inY;
	cin >> inY >> inX;
	cin.ignore();

	for (int y = 0; y < inY; ++y)
		for (int x = 0; x < inX; ++x)
			fireStep[y][x] = INT16_MAX;

	Pos startJ;

	vector<Pos> startFirePoses;

	for (int i = 0; i < inY; ++i)
	{
		string line;
		getline(cin, line);
		int idx = 0;

		for (char c : line)
		{
			if (c == 'J')
				startJ = { i, idx };

			if (c == 'F')
			{
				Pos fireStart = { i, idx };
				startFirePoses.push_back(fireStart);
			}

			if (c == '#')
				fireStep[i][idx] = 0;

			idx++;
		}
	}

	
	// fireStep[i][y][x]
	// i 시점
	// y, x 좌표

	int stepIdx = 0;

	queue<Pos> fQueue;

	for (int i = 0; i < startFirePoses.size(); ++i)
	{
		Pos fireStart = startFirePoses[i];
		fireStep[fireStart.m_y][fireStart.m_x] = 0;
		fQueue.push(fireStart);
	}

	while (fQueue.empty() == false)
	{
		Pos nowFire = fQueue.front();
		fQueue.pop();

		// 다음 시점 계산
		stepIdx = fireStep[nowFire.m_y][nowFire.m_x] + 1;

		// 아직 시점이 갱신 안되었으면 불이 붙을 수 있음
		// 위
		if (nowFire.m_y - 1 >= 0 && fireStep[nowFire.m_y - 1][nowFire.m_x] == INT16_MAX)
		{
			fireStep[nowFire.m_y - 1][nowFire.m_x] = stepIdx;
			fQueue.push(Pos(nowFire.m_y - 1, nowFire.m_x));
		}

		// 아래
		if (nowFire.m_y + 1 < inY && fireStep[nowFire.m_y + 1][nowFire.m_x] == INT16_MAX)
		{
			fireStep[nowFire.m_y + 1][nowFire.m_x] = stepIdx;
			fQueue.push(Pos(nowFire.m_y + 1, nowFire.m_x));
		}

		// 왼쪽
		if (nowFire.m_x - 1 >= 0 && fireStep[nowFire.m_y][nowFire.m_x - 1] == INT16_MAX)
		{
			fireStep[nowFire.m_y][nowFire.m_x - 1] = stepIdx;
			fQueue.push(Pos(nowFire.m_y, nowFire.m_x - 1));
		}

		// 오른쪽
		if (nowFire.m_x + 1 < inX && fireStep[nowFire.m_y][nowFire.m_x + 1] == INT16_MAX)
		{
			fireStep[nowFire.m_y][nowFire.m_x + 1] = stepIdx;
			fQueue.push(Pos(nowFire.m_y, nowFire.m_x + 1));
		}
	}

	// 비었으니까 재활용
	fQueue.push(startJ);
	int ret = 0;
	fireStep[startJ.m_y][startJ.m_x] = 0;
	stepIdx = 0;
	while (fQueue.empty() == false)
	{
		Pos nowPos = fQueue.front();
		fQueue.pop();

		// 다음 step 계산
		stepIdx = fireStep[nowPos.m_y][nowPos.m_x] - 1;

		// 탈출
		if (nowPos.m_x + 1 >= inX || nowPos.m_y + 1 >= inY || nowPos.m_x - 1 < 0 || nowPos.m_y - 1 < 0)
		{
			ret = abs(stepIdx);
			break;
		}

		// 불이 붙은 시점이 이동시점보다 크다면 이동 가능
		// 지훈이 간 시점은 음수로 표기하므로 이미 간 길은 가지 않음
		// 위
		if (fireStep[nowPos.m_y - 1][nowPos.m_x] > abs(stepIdx))
		{
			fireStep[nowPos.m_y - 1][nowPos.m_x] = stepIdx;
			fQueue.push(Pos{ nowPos.m_y - 1, nowPos.m_x});
		}

		// 아래
		if (fireStep[nowPos.m_y + 1][nowPos.m_x] > abs(stepIdx))
		{
			fireStep[nowPos.m_y + 1][nowPos.m_x] = stepIdx;
			fQueue.push(Pos{ nowPos.m_y + 1, nowPos.m_x });
		}

		// 왼쪽
		if (fireStep[nowPos.m_y][nowPos.m_x - 1] > abs(stepIdx))
		{
			fireStep[nowPos.m_y][nowPos.m_x - 1] = stepIdx;
			fQueue.push(Pos{ nowPos.m_y, nowPos.m_x - 1 });
		}

		// 오른쪽
		if (fireStep[nowPos.m_y][nowPos.m_x + 1] > abs(stepIdx))
		{
			fireStep[nowPos.m_y][nowPos.m_x + 1] = stepIdx;
			fQueue.push(Pos{ nowPos.m_y, nowPos.m_x + 1 });
		}
	}

	if (ret != 0)
	{
		cout << ret << endl;
	}
	else
	{
		cout << "IMPOSSIBLE" << endl;
	}
}