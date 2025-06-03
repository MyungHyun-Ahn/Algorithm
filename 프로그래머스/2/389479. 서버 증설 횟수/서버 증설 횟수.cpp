#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0; // 증설 카운트
    
    int n = 0; // 현재 서버 대수
    // 증설 정보를 담을 벡터
    deque<pair<int, int>> infos; // <유지시간, 대수>
    
    for (int i = 0; i < players.size(); i++)
    {   
        // 만료처리
        if (!infos.empty()) // 비어있지 않다면
        { // 제일 앞에꺼 확인
            if (infos.front().first == i)
            {
                n -= infos.front().second;
                infos.pop_front();
            }
        }
        
        int playerCount = players[i];
        if (playerCount < m * (n + 1)) // 증설 필요 없음
            continue;
        
        int addCount = ((playerCount + m) - m * (n + 1)) / m;
        
        // 증설해야 한다면?
        infos.emplace_back(make_pair(i + k, addCount));
        n += addCount;
        answer += addCount;
    }
    
    return answer;
}