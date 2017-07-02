#include <cstdio>
int Arr[2][100010], Dp[2][100010]; // Dp[i][j] = i번째 행 j번째 열 까지 스티커를 뜯었을 때 최대 이득
int max(int x, int y) { return x > y ? x : y; }
int main() {
    int TC;
    scanf("%d", &TC); // TestCase 갯수 입력
    while(TC--) {
        int n;
        scanf("%d", &n); // n 입력
        for(int i = 0; i < 2; ++i) {
            for(int j = 1; j <= n; ++j) scanf("%d", &Arr[i][j]); // 스티커 점수 입력
        }
        for(int i = 1; i <= n; ++i) {
            // Dp[i][j] 가 Dp[i][j - 2] 값을 참조 하지 않는 이유는 Dp(i, j - 2)값을 참조하는 것보다 Dp(반대쪽 행, j - 1) 값을 참조하는게 이득이기 때문이다.
            // Dp(반대쪽 행, j - 1)에서 Dp(i, j - 2) 를 선택하는 경우를 봐주기 때문에 항상 반대쪽행의 j - 1을 참조하는 것이 이득이다.
            Dp[0][i] = max(Dp[1][i - 2], Dp[1][i - 1]) + Arr[0][i]; // 0번째 행의 스티커는 1번째 행의 i - 1, i - 2 중 큰 값을 뜯는게 가장 이득이다.
            Dp[1][i] = max(Dp[0][i - 2], Dp[0][i - 1]) + Arr[1][i]; // 1번째 행의 스티커는 0번째 행의 i - 1, i - 2 중 큰 값을 뜯는게 가장 이득이다.
        }
        printf("%d\n", max(Dp[0][n], Dp[1][n])); // 0번째 행에서 끝났을 때와 1번째 행에서 끝났을 때 중 큰 값 출력
    }
}
