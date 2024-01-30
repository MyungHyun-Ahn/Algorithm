#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

vector<bool> g_IsUsed;
vector<vector<string>> g_Tickets;
vector<string> answer;

void dfs(string str, int idx)
{
	static bool isAnswer = false;
	answer.push_back(str);

	// idx와 티켓 수가 같으면 끝
	// 0번 부터 시작이니까 size - 1
	if (idx == g_Tickets.size())
		isAnswer = true;

	// 루프 돌면서 탐색
	for (int i = 0; i < g_Tickets.size(); i++)
	{
		// 티켓 사용 여부
		if (g_IsUsed[i])
			continue;

		if (g_Tickets[i][0] == str)
		{
			// 사용처리
			g_IsUsed[i] = true;
			dfs(g_Tickets[i][1], idx + 1);

			// 답이 아니면 값 빼서 다음거 찾기 
			if (!isAnswer)
			{
				answer.pop_back();
				g_IsUsed[i] = false;
			}
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	map<string, vector<string>> nodes;
	g_IsUsed = vector<bool>(500, false);
	sort(tickets.begin(), tickets.end());
	g_Tickets = tickets;

	dfs("ICN", 0);
	return answer;
}