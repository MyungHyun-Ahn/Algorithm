#include <iostream>
#include <string>

using namespace std;

/*
로직 설명
- 이 나오기 전까지 계속 더함
다음 뺄셈 연산이 나오면 빼줌
*/

int main()
{
	string str;

	getline(cin, str);

	int ret = 0;
	int tempNum = 0;

	bool isFirst = true;
	bool LastOpIsPlus = true;

	string temp;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '+')
		{
			// tempNum에 덧셈 연산자면 계속 더함
			int num = atoi(temp.c_str());
			tempNum += num;
			temp.clear();
			continue;
		}

		if (str[i] == '-')
		{
			// 마지막 연산자에 + 을 해야하는지 판단 - 이 한번이라도 있었다면 무조건 -
			LastOpIsPlus = false;

			int num = atoi(temp.c_str());
			temp.clear();
			tempNum += num;

			// 처음 뺄셈이 나왔으면 ret에 덧셈
			if (isFirst)
			{
				isFirst = false;
				ret = tempNum;
			}
			else
			{
				ret -= tempNum;
			}

			// 연산에 사용했으니 초기화
			tempNum = 0;

			continue;
		}

		temp += str[i];
	}

	// 마지막 작업
	if (temp.empty() == false)
	{
		int num = atoi(temp.c_str());
		temp.clear();
		tempNum += num;

		// 마지막 연산자 비교해서 처리
		if (LastOpIsPlus)
			ret += tempNum;
		else
			ret -= tempNum;
	}

	cout << ret << endl;
}