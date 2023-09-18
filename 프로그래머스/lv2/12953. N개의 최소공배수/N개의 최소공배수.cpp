#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int n = 1;
    while (true)
    {
        
        bool isDiv = true;
        for (auto a : arr)
        {
            if (n % a != 0)
            {
                isDiv = false;
            }
        }
        
        if (isDiv)
        {
            answer = n;
            break;
        }
        
        ++n;
    }
    
    return answer;
}