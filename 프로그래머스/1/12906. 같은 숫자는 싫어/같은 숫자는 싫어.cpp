#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prevNum = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == prevNum)
            continue;
        
        answer.push_back(arr[i]);
        prevNum = arr[i];
    }

    return answer;
}