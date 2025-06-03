#include <string>
#include <vector>
#include <deque>

using namespace std;

// bridge_length 대 초만큼 다리에 있음
// 트럭 최대 bridge_length 대까지 올라갈 수 있고
// weight 이하의 무게 견딜 수 있음
// 

int solution(int bridge_length, int weight, vector<int> truck_weights) {  
    int n = truck_weights.size();
    
    // 나와야 하는 타이밍, 무게
    deque<pair<int, int>> bridgeQueue;
    // 현재 다리 무게
    int currentWeight = 0;
    int time = 0;
    int truckIndex = 0;
    while (!(bridgeQueue.empty() && truckIndex == n))
    {
        if (!bridgeQueue.empty())
        {
            auto truck = bridgeQueue.front();
            if (time == truck.first)
            {
                currentWeight -= truck.second;
                bridgeQueue.pop_front();
            }
        }
        
        if (truckIndex < n)
        {
            int truckWeight = truck_weights[truckIndex];
            if (currentWeight + truckWeight <= weight)
            {
                currentWeight += truckWeight;
                bridgeQueue.emplace_back(make_pair(time + bridge_length, truckWeight));
                truckIndex++;
            }   
        }
        time++;
    }
    
    return time;
}