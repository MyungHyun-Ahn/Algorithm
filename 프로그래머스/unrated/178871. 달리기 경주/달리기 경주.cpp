#include <string>
#include <vector>

using namespace std;

#include <map>

vector<string> solution(vector<string> players, vector<string> callings) {
	map<string, int> map;

	int index = 0;
	for (auto it = players.begin(); it != players.end(); ++it)
	{
		map.insert(make_pair(*it, index++ ));
	}

	for (auto it = callings.begin(); it != callings.end(); ++it)
	{
		auto findIt = map.find(*it);
		string prev = players[--findIt->second];
		players[findIt->second] = findIt->first;

		findIt = map.find(prev);
		players[++findIt->second] = findIt->first;
	}

	return players;
}