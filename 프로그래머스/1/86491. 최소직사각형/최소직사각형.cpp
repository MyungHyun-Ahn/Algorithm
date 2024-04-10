#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxWidth = 0;
    int maxHeight = 0;
    
    for (auto &vec : sizes)
    {
        if (vec[0] > vec[1])
        {
            std::swap(vec[0], vec[1]);
        }
        
        maxWidth = maxWidth < vec[0] ? vec[0] : maxWidth;
        maxHeight = maxHeight < vec[1] ? vec[1] : maxHeight;
    }
    
    return maxWidth * maxHeight;
}