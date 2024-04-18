#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> split(string input, char delimiter)
{
	std::vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<string, map<string, int>> idMap;
    
    map<string, int> idIndex;
    
    for (int i = 0; i < id_list.size(); i++)
    {
        map<string, int> m;
        idMap[id_list[i]] = m;
        idIndex[id_list[i]] = i;
    }
    
    for (string re : report)
    {
        vector<string> tok = split(re, ' ');
        
        idMap[tok[1]][tok[0]] = 1;
    }
    
    for (auto it1 = idMap.begin(); it1 != idMap.end(); ++it1)
    {
        if (it1->second.size() < k)
            continue;
        
        for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
        {
            answer[idIndex[it2->first]]++;
        }
    }
    
    return answer;
}