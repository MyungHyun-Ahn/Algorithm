#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> st;
    st.push_back(0);
	
	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[j][moves[i] - 1] != 0)
			{
				if (st.back() == board[j][moves[i] - 1])
				{
					st.pop_back();
					answer += 2;
				}
				else
					st.push_back(board[j][moves[i] - 1]);

				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}

	return answer;
}