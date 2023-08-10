#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;

	int w = park[0].size();
	int h = park.size();
	int posX = 0;
	int posY = 0;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (park[y][x] == 'S')
			{
				posX = x;
				posY = y;
				break;
			}
		}
	}

	int direction[2] = { 0, 0 };

	for (auto it = routes.begin(); it != routes.end(); ++it)
	{
		switch ((*it)[0])
		{
		case 'N':
			direction[0] = -1;
			direction[1] = 0;
			break;
		case 'S':
			direction[0] = 1;
			direction[1] = 0;
			break;
		case 'W':
			direction[0] = 0;
			direction[1] = -1;
			break;
		case 'E':
			direction[0] = 0;
			direction[1] = 1;
			break;
		}

		bool canGo = true;
		int goCount = static_cast<int>((*it)[2]) - '0';
		for (int i = 1; i <= goCount; i++)
		{
			if (posY + (i * direction[0]) > h - 1 || posX + (i * direction[1]) > w - 1 || posY + (i * direction[0]) < 0 || posX + (i * direction[1]) < 0)
			{
				canGo = false;
				break;
			}

			if (park[posY + (i * direction[0])][posX + (i * direction[1])] == 'X')
			{
				canGo = false;
				break;
			}
		}

		if (canGo)
		{
			posY = posY + goCount * direction[0];
			posX = posX + goCount * direction[1];
		}

	}

	answer.push_back(posY);
	answer.push_back(posX);
	return answer;
}