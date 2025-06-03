#include<vector>
#include <queue>
using namespace std;

struct Node
{
    int y;
    int x;
    int count;
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    // bfs 구현
    int m = maps.size();
    int n = maps[0].size();
    
    // 도착점은 (m-1, n-1) - (y, x)
    
    int visited[100][100] = {0, };
    
    // 시작점 설정
    std::queue<Node> bfsQueue;
    Node startNode{0, 0, 1};
    visited[0][0] = 1;
    bfsQueue.push(startNode);
    
    while(!bfsQueue.empty())
    {
        Node node = bfsQueue.front();
        bfsQueue.pop();
        
        if (node.y == m - 1 && node.x == n - 1)
        {
            answer = node.count;
            break;
        }
        
        // 상
        if (node.y - 1 >= 0 && !visited[node.y - 1][node.x] && maps[node.y - 1][node.x])
        {
            Node nextNode{node.y - 1, node.x, node.count + 1};
            visited[node.y - 1][node.x] = 1;
            bfsQueue.push(nextNode);
        }
            
        // 하
        if (node.y + 1 < m && !visited[node.y + 1][node.x] && maps[node.y + 1][node.x])
        {
            Node nextNode{node.y + 1, node.x, node.count + 1};
            visited[node.y + 1][node.x] = 1;
            bfsQueue.push(nextNode);
        }
        
        // 좌
        if (node.x - 1 >= 0 && !visited[node.y][node.x-1] && maps[node.y][node.x - 1])
        {
            Node nextNode{node.y, node.x - 1, node.count + 1};
            visited[node.y][node.x - 1] = 1;
            bfsQueue.push(nextNode);
        }
        
        // 우
        if (node.x + 1 < n && !visited[node.y][node.x+1] && maps[node.y][node.x + 1])
        {
            Node nextNode{node.y, node.x + 1, node.count + 1};
            visited[node.y][node.x + 1] = 1;
            bfsQueue.push(nextNode);
        }
    }
    
    return answer;
}