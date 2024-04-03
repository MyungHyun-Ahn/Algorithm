#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int startDay = 0;
    while (startDay + 10 <= discount.size())
    {   
        std::map<string, int> m;
        for (int i = startDay; i < startDay + 10; i++)
        {   
            auto it = m.find(discount[i]);
            if (it == m.end())
            {
                m[discount[i]] = 0;
            }
            // 개수 세기
            m[discount[i]] += 1;
        }
        
        bool flag = true;
        for (int i = 0; i < want.size(); i++)
        {
            if (m[want[i]] < number[i])
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
            answer++;
        
        startDay++;
    }
    
    return answer;
}