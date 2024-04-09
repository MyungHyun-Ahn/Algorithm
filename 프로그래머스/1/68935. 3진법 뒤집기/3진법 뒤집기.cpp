#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	vector<int> threeNums;
	while (n > 0)
	{
		// 45
		// 15 --- 0
		// 5 --- 0
		// 1 --- 2
		// 0 --- 1
		threeNums.push_back(n % 3);

		n /= 3;
	}

	int x = 1;
	while (!threeNums.empty())
	{
		int num = threeNums.back();
		threeNums.pop_back();
		answer += num * x;
		x *= 3;
	}

	return answer;
}