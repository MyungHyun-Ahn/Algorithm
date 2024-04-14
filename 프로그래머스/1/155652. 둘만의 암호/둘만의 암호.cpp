#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (char &c : s)
    {
        for (int i = 0; i < index; )
        {
            c++;
            if (c == 'z' + 1) 
                c = 'a';
            for (int j = 0; j < skip.size(); j++)
                // 스킵 문자면
                if (c == skip[j])
                    goto GO;
            i++;
GO:
            c;
        }
    }
    
    return s;
}