#include <string>
#include <vector>
#include <map>

#define STU1_MAX 5
#define STU2_MAX 8
#define STU3_MAX 10


using namespace std;

int g_arrStudent1[STU1_MAX] = { 1, 2, 3, 4, 5 };
int g_arrStudent2[STU2_MAX] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int g_arrStudent3[STU3_MAX] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {

	int stu1Corr = 0;
	int stu2Corr = 0;
	int stu3Corr = 0;

	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == g_arrStudent1[i % STU1_MAX])
		{
			stu1Corr++;
		}

		if (answers[i] == g_arrStudent2[i % STU2_MAX])
		{
			stu2Corr++;
		}

		if (answers[i] == g_arrStudent3[i % STU3_MAX])
		{
			stu3Corr++;
		}
	}

	map<int, vector<int>, greater<int>> stuMap;
	stuMap[stu1Corr].push_back(1);
	stuMap[stu2Corr].push_back(2);
	stuMap[stu3Corr].push_back(3);

	vector<int> answer = stuMap.begin()->second;

	return answer;
}