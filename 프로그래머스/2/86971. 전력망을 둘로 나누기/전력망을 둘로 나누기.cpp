#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// DFS를 통해 네트워크(트리)의 크기를 구하는 함수
int dfs(int node, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[node] = true;
    int count = 1;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            count += dfs(neighbor, visited, graph);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;  // 최대 차이 n으로 초기화

    // 모든 전선을 하나씩 끊어본다
    for (int i = 0; i < wires.size(); ++i) {
        // 인접 리스트 초기화
        vector<vector<int>> graph(n + 1);

        // 전선 i번을 제외하고 연결
        for (int j = 0; j < wires.size(); ++j) {
            if (i == j) continue; // 이 전선은 끊는다
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // DFS로 한 쪽 송전탑 개수 구하기
        vector<bool> visited(n + 1, false);
        int count = dfs(1, visited, graph); // 한 쪽 트리의 크기

        // 나머지 쪽은 전체 - count
        int diff = abs(count - (n - count));
        answer = min(answer, diff);
    }

    return answer;
}