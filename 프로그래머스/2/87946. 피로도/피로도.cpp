#include <string>
#include <vector>

using namespace std;

int num = 0;
bool visited[9] = { 0, };

int dfs(int count, int k, vector<vector<int>> dungeons)
{
    if(count > num) num = count;
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(visited[i] == false && dungeons[i][0] <= k)
        {
            visited[i] = true;
            dfs(count + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
    return 0;
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return num;
}