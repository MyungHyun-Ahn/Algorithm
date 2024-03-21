#include <string>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	int round[3] = { 0, }; // 0, 1, 2 각각 기회 1, 2, 3

	int curRound = -1;
	for (int i = 0; i < dartResult.size(); i++)
	{
		char c = dartResult[i];
		switch (c)
		{
		case 'S':
			break;

		case 'D':
			round[curRound] = round[curRound] * round[curRound];
			break;
		case 'T':
			round[curRound] = round[curRound] * round[curRound] * round[curRound];
			break;

		case '*':
			round[curRound] *= 2;
			if (curRound != 0)
				round[curRound - 1] *= 2;
			break;

		case '#':
			round[curRound] *= -1;
			break;

		case '0':
			// 이전 문자가 숫자가 아닌 경우
			if (curRound == -1 || !(dartResult[i - 1] > '0' && dartResult[i - 1] < '9'))
			{
				curRound++;
			}

			round[curRound] *= 10;
			break;

		default:
			++curRound;
			int n = c - '0';
			round[curRound] = n;
			break;
		}

	}

	answer = round[0] + round[1] + round[2];

	return answer;
}