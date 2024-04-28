#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);

	// first 가격, second 넣은 시점
	vector<std::pair<int, int>> vec;

	for (int i = 0; i < prices.size(); i++)
	{
		while (!vec.empty())
		{
			std::pair<int, int> t = vec.back();
			
			// 가격이 떨어짐
			if (prices[i] < t.first)
			{
				answer[t.second] = i - t.second;
				vec.pop_back();
			}
			else // 떨어지지 않았다면 break
				break;
		}

		vec.push_back(std::make_pair(prices[i], i));
	}

	while (!vec.empty())
	{
		std::pair<int, int> t = vec.back();
		vec.pop_back();
		answer[t.second] = prices.size() - 1 - t.second;

	}

	return answer;
}