#include <string>
#include <vector>

using namespace std;

int answer = 0;
int numCount = 0;
int targetNum = 0;

// flag true 면 INC, false 면 DEC
void dfs(vector<int> &numbers, int index, int sum)
{
    // index가 num 개수만큼 되면 숫자를 다 쓴 것
    if (index == numCount)
    {
        if (sum == targetNum)
        {
            answer++;
        }
        
        return;
    }
    
    dfs(numbers, index + 1, sum + numbers[index]);
    dfs(numbers, index + 1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    numCount = numbers.size();
    targetNum = target;
    
    // 완전 탐색 DFS
    dfs(numbers, 0, 0);
    
    return answer;
}