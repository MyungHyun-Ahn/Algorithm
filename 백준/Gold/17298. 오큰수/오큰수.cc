#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	std::vector<int> st;

	int n;
	std::cin >> n;

	std::vector<int> ret(n, 0);

	v.reserve(n);
	int retIndex = 0;
	for (int i = 0; i < n; ++i)
	{
		int value;
		std::cin >> value;
		
		v.push_back(value);
	}

	st.push_back(v.back());
	ret[n - 1] = -1; // 맨 오른쪽 값은 오큰수가 없으므로


	for (int i = n - 2; i >= 0; --i)
	{
		int num = v[i];

		while (!st.empty() && num >= st.back())
		{
			st.pop_back();
		}

		ret[i] = st.empty() ? -1 : st.back();
		st.push_back(num);
	}

	for (int i = 0; i < ret.size(); ++i)
	{
		std::cout << ret[i] << " ";
	}

	return 0;
}
