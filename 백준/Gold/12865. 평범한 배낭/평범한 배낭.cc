#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Knapsack 알고리즘을 이용한 최대 가치 계산
int knapsack(int N, int K, vector<int>& weights, vector<int>& values) {
	// dp[i][j]: 0부터 i까지의 아이템을 고려하고, 무게 j까지 사용할 때의 최대 가치
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			// 현재 아이템을 선택하지 않는 경우
			dp[i][j] = dp[i - 1][j];

			// 현재 아이템을 선택하는 경우
			if (j >= weights[i - 1]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
			}
		}
	}

	return dp[N][K];
}

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> weights(N);
	vector<int> values(N);

	// 아이템 정보 입력
	for (int i = 0; i < N; ++i) {
		cin >> weights[i] >> values[i];
	}

	int result = knapsack(N, K, weights, values);
	cout  << result << endl;

	return 0;
}