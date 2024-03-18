#include <string>
#include <vector>
#include <cmath>

#define NUMBER 100001

using namespace std;


// 약수 테이블
int table[NUMBER] = {0,};

int solution(int number, int limit, int power) {
    int answer = 0;
    
    // 약수 테이블 채우기
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= number / i; j++)
        {
            table[i * j]++;
        }
    }
    
    // 문제 로직
    for (int i = 1; i <= number; i++)
    {
        if (table[i] > limit)
        {
            answer += power;
            continue;
        }
        
        answer += table[i];
    }
    
    return answer;
}