#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    int DP[100001][4] = {0};
    
    DP[0][0] = land[0][0];
    DP[0][1] = land[0][1];
    DP[0][2] = land[0][2];
    DP[0][3] = land[0][3];
    
    for (int i = 1; i < land.size(); i++)
    {
        DP[i][0] = max(DP[i][0], DP[i - 1][1] + land[i][0]);
        DP[i][0] = max(DP[i][0], DP[i - 1][2] + land[i][0]);
        DP[i][0] = max(DP[i][0], DP[i - 1][3] + land[i][0]);
        DP[i][1] = max(DP[i][1], DP[i - 1][0] + land[i][1]);
        DP[i][1] = max(DP[i][1], DP[i - 1][2] + land[i][1]);
        DP[i][1] = max(DP[i][1], DP[i - 1][3] + land[i][1]);
        DP[i][2] = max(DP[i][2], DP[i - 1][0] + land[i][2]);
        DP[i][2] = max(DP[i][2], DP[i - 1][1] + land[i][2]);
        DP[i][2] = max(DP[i][2], DP[i - 1][3] + land[i][2]);
        DP[i][3] = max(DP[i][3], DP[i - 1][0] + land[i][3]);
        DP[i][3] = max(DP[i][3], DP[i - 1][1] + land[i][3]);
        DP[i][3] = max(DP[i][3], DP[i - 1][2] + land[i][3]);
    }
    
    answer = max(DP[land.size()-1][0], DP[land.size()-1][1]);
    answer = max(answer, DP[land.size()-1][2]);
    answer = max(answer, DP[land.size()-1][3]);

    return answer;
}