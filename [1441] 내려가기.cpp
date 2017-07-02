#include <cstdio>
int Dp[100010][3][2]; // Dp[i][j][0] = i행 j열 까지 내려 왔을 때 최대 // Dp[i][j][1] = i행 j열 까지 내려 왔을 때 최소
int min(int x, int y) { return x < y ? x : y; } // x, y 중 작은 값 return
int max(int x, int y) { return x > y ? x : y; } // x, y 중 큰 값 return
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d %d %d", &Dp[i][0], &Dp[i][1], &Dp[i][2]); // 점수 입력
        Dp[i][0][1] = Dp[i][0][0]; // Dp배열 초기화
        Dp[i][1][1] = Dp[i][1][0]; // Dp배열 초기화
        Dp[i][2][1] = Dp[i][2][0]; // Dp배열 초기화
        // Dp[i][j][0]은 위로 인접한 부분 중 가장 큰 값을 참조한다. Dp[i][j][0] = Dp(위로 인접한 i, j 중 최대)
        Dp[i][0][0] += max(Dp[i - 1][0][0], Dp[i - 1][1][0]);
        Dp[i][1][0] += max(Dp[i - 1][0][0], max(Dp[i - 1][1][0], Dp[i - 1][2][0]));
        Dp[i][2][0] += max(Dp[i - 1][1][0], Dp[i - 1][2][0]);
        // Dp[i][j][1]은 위로 인접한 부분 중 가장 작은 값을 참조한다. Dp[i][j][1] = Dp(위로 인접한 i, j 중 최소)
        Dp[i][0][1] += min(Dp[i - 1][0][1], Dp[i - 1][1][1]);
        Dp[i][1][1] += min(Dp[i - 1][0][1], min(Dp[i - 1][1][1], Dp[i - 1][2][1]));
        Dp[i][2][1] += min(Dp[i - 1][1][1], Dp[i - 1][2][1]);
    }
    // 마지막 줄까지 내려왔을 때 최대값과 최소값을 구한 후 출력한다.
    printf("%d %d", max(Dp[N][0][0], max(Dp[N][1][0], Dp[N][2][0])), min(Dp[N][0][1], min(Dp[N][1][1], Dp[N][2][1])));
}
