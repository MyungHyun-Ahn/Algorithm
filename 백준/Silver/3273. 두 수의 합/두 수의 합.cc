#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
	int n; 
	cin >> n;

	vector<ll> li;

	for (int i = 0; i < n; ++i)
	{
		ll num;
		cin >> num;
		li.push_back(num);
	}

	sort(li.begin(), li.end());

	int x;
	cin >> x;

	int ret = 0;
	int p1 = 0;
	int p2 = li.size() - 1;

	while (p1 < p2)
	{
		ll sum = li[p1] + li[p2];

		if (sum > x)
		{
			--p2;
		}
		else if (sum < x)
		{
			++p1;
		}
		else
		{
			++ret;
			--p2;
		}
	}

	cout << ret << endl;
}