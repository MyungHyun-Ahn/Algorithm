#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec;
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int p1 = 0; 
	int p2 = 0;
	int ret = INT32_MAX;

	while (p1 < vec.size() && p2 < vec.size())
	{
		int diff = vec[p2] - vec[p1];
		if (diff < m)
		{
			++p2;
		}
		else
		{
			ret = min(ret, diff);
			++p1;
		}
	}
	cout << ret << endl;
}