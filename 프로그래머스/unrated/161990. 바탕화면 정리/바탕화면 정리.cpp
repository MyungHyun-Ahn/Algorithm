#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int w = wallpaper[0].size();
    int h = wallpaper.size();
    
    int minX = w;
    int minY = h;
    int maxX = 0;
    int maxY = 0;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (wallpaper[y][x] == '#')
            {
                if (x > maxX)
                {
                    maxX = x;
                }
                
                if (y > maxY)
                {
                    maxY = y;
                }
                
                if (x < minX)
                {
                    minX = x;
                }
                
                if (y < minY)
                {
                    minY = y;
                }   
            }
        }
    }
    
    answer.push_back(minY);
    answer.push_back(minX);
    answer.push_back(maxY + 1);
    answer.push_back(maxX + 1);
    
    return answer;
}