#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int maxY = ((n / w) + ((n % w) <= 0 ? 0 : 1) - 1);
    // 최고층은 증가? 감소?
    int maxDir = ((maxY % 2 == 0) ? 1 : 0);
    int y = (num - 1) / w; // 자신이 몇번째 라인에 있는지
    // 내 위로 최대 몇층?
    int def = maxY - y;
    // 나는 몇번째 위치?
    int numDir = ((y % 2 == 0) ? 1 : 0);
    int myIndex;
    if (numDir) // 증가하는 방향이면
    {
        int startX = 1 + w * y;
        myIndex = num - startX;
    }
    else
    {
        int startX = w * (y + 1);
        myIndex = startX - num;
    }
    int isHigh;
    if (maxDir) // 증가하는 방향이면
    {
        int startX = 1 + w * maxY;
        // 나와 대응되는 값은
        isHigh = startX + myIndex;
    }
    else
    {
        int startX = w * (maxY + 1);
        isHigh = startX - myIndex;
    }

    if (isHigh > n) // 존재하는 index?
    {
        def -= 1;
    }

    return def + 1; // 자신 상자 포함
}
