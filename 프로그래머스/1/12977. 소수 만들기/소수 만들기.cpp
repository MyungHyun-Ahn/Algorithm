#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    std::vector<int> arrSum;
    
    for (int a = 0; a < nums.size() - 2; a++)
    {
        for (int b = a + 1; b < nums.size() - 1; b++)
        {
            for (int c = b + 1; c < nums.size(); c++)
            {
                arrSum.emplace_back(nums[a] + nums[b] + nums[c]);
            }
        }
    }
    
    // 소수 판별
    for (int num : arrSum)
    {
        int count = 0;
        for (int i = 2; i * i <= num; i++)
        {
            if ((num % i) == 0)
            {
                count++;
                break;
            }
        }
        
        if (count == 0)
        {
            answer++;
        }
    }

    return answer;
}