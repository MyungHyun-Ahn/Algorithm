#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;

    string tmp;
    for (int i = 1; i < s.length() - 1; i++){
      if (s[i] != '{' && s[i] != '}' && s[i] != ',') {
        tmp += s[i];
        if (s[i+1] != ',' && s[i+1] != '}') continue;
        m[stoi(tmp)]++; // 원소 카운팅
      }
      tmp = "";
    }

    vector<pair<int,int>> vec( m.begin(), m.end() );
	sort(vec.begin(), vec.end(), cmp);

    for (auto num : vec)
      answer.emplace_back(num.first);

    return answer;
}