#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 메모이제이션: dp[idx][a_sum][b_sum]
int dp[41][121][121];

int dfs(int idx, int a_sum, int b_sum, const vector<vector<int>>& info, int n, int m) {
    if (a_sum >= n || b_sum >= m) return 1e9; // 경찰에 잡힘
    if (idx == info.size()) return a_sum;     // 모든 물건을 처리한 경우

    int& ret = dp[idx][a_sum][b_sum];
    if (ret != -1) return ret;

    ret = 1e9;
    // A가 훔친 경우
    ret = min(ret, dfs(idx + 1, a_sum + info[idx][0], b_sum, info, n, m));
    // B가 훔친 경우
    ret = min(ret, dfs(idx + 1, a_sum, b_sum + info[idx][1], info, n, m));

    return ret;
}

int solution(vector<vector<int>> info, int n, int m) {
    memset(dp, -1, sizeof(dp));
    int res = dfs(0, 0, 0, info, n, m);
    return res >= 1e9 ? -1 : res;
}