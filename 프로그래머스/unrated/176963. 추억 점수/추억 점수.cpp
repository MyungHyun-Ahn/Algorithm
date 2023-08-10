#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    
    for (int i = 0; i < name.size(); i++)
    {
        m.insert(make_pair(name[i], yearning[i]));
    }
    
    for (auto it = photo.begin(); it != photo.end(); ++it)
    {
        int sum = 0;
        for(auto it2 = (*it).begin(); it2 != (*it).end(); ++it2)
        {
            auto findIt = m.find(*it2);
            if (findIt != m.end())
                sum += findIt->second;
        }
        answer.push_back(sum);
    }
    
    return answer;
}