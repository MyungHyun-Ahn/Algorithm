#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) 
{
    int answer = 0;
    vector<int> ham = { -1 };
    for(int x : ingredient)
    {
        // back이 1이고 x가 2번 12로 back을 교체
        if(ham.back() == 1 && x == 2) 
            ham.back() = 12;
        // 3 붙이기
        else if(ham.back() == 12 && x == 3) 
            ham.back() = 123;
        // 123에 1이 들어오면 햄버거 완성
        else if(ham.back() == 123 && x == 1) 
        {
            answer++; 
            ham.pop_back();   
        }
        else 
            ham.push_back(x);
    }    

    return answer;
}