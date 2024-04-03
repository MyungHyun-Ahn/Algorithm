#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    sort(X.begin(), X.end(), greater<>());
    sort(Y.begin(), Y.end(), greater<>());
    
    int length = X.length() < Y.length() ? X.length() : Y.length();
    int i = 0;
    int j = 0;
    while (i < length || j < length)
    {
        if (X[i] == Y[j])
        {
            answer += X[i];
            i++;
            j++;
            continue;
        }
        
        if (X[i] < Y[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    
    if (answer.length() == 0)
        answer = "-1";
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}