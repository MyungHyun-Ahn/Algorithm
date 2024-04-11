#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int g_sort_by;

bool customOperator(vector<int> &v1, vector<int> &v2)
{
    return v1[g_sort_by] < v2[g_sort_by];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    
    map<string, int> extNames;
    extNames["code"] = 0;
    extNames["date"] = 1;
    extNames["maximum"] = 2;
    extNames["remain"] = 3;
    
    int index = extNames[ext];
    g_sort_by = extNames[sort_by];
    
    for (auto d : data)
    {
        if (d[index] < val_ext)
            answer.push_back(d);
    }
    
    sort(answer.begin(), answer.end(), customOperator);
    
    return answer;
}