#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, vCnt;
vector<vector<int>> v;
vector<bool> visited;

void Dfs(int here)
{
	visited[here] = true;
	cout << here + 1 << " ";

	for (int there : v[here])
	{
		if (visited[there] == false)
			Dfs(there);
	}
}

void Bfs(int here)
{
	queue<int> q;

	// 시작 정점을 큐 push하고 발견 여부 체크
	q.push(here);
	visited[here] = true;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << here + 1 << " ";

		// here의 연결 간선 방문
		for (int line : v[here])
		{
			// 이미 발견 했으면 Pass
			if (visited[line] == true)
				continue;

			// 발견하지 않았으면 큐에 push
			q.push(line);
			visited[line] = true;
		}
	}
}

int main()
{
	cin >> n >> m >> vCnt;
	v = vector<vector<int>>(n);
	visited = vector<bool>(n, false);

	// 양방향 간선 등록
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}

	// 간선 벡터 정렬
	for (int i = 0; i < n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	Dfs(vCnt - 1);
	cout << endl;

	visited = vector<bool>(n, false);

	Bfs(vCnt - 1);
	cout << endl;

}