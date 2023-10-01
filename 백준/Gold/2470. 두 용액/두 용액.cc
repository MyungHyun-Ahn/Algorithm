#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> li;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		li.push_back(num);
	}

	sort(li.begin(), li.end());

	int minValue = INT32_MAX;
	int ret1, ret2;

	int p1 = 0;
	int p2 = li.size() - 1;

	while (p1 < p2)
	{
		int sum = li[p1] + li[p2];

		if (abs(sum) < minValue)
		{
			minValue = abs(sum);
			ret1 = li[p1];
			ret2 = li[p2];

			if (sum == 0)
				break;
		}
		
		if (sum < 0)
			++p1;
		else
			--p2;
	}

	cout << ret1 << " " << ret2 << endl;
}