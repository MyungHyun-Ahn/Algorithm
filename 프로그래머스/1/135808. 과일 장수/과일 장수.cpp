#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    // 정렬하고
    sort(score.begin(), score.end(), greater<>());
    
    int nextIdx = m;
    
    while (nextIdx <= score.size())
    {
        answer += score[nextIdx - 1] * m;
        nextIdx += m;
    }
    return answer;
}