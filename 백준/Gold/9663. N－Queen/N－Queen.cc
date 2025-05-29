#include <stdio.h>

int N;
int count = 0;
bool col[15];        // 세로(열) 체크
bool diag1[30];      // '/' 방향 대각선 체크 (row + col)
bool diag2[30];      // '\' 방향 대각선 체크 (row - col + N)

void backtrack(int row) {
    if (row == N) {
        count++;
        return;
    }

    for (int c = 0; c < N; ++c) {
        if (col[c] || diag1[row + c] || diag2[row - c + N])
            continue;

        col[c] = diag1[row + c] = diag2[row - c + N] = true;
        backtrack(row + 1);
        col[c] = diag1[row + c] = diag2[row - c + N] = false;
    }
}

int main() {
    scanf("%d", &N);
    backtrack(0);
    printf("%d\n", count);
    return 0;
}