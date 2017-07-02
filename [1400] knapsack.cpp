#include <cstdio>
int weight[101], value[101], Dp[101][10010]; // Dp[i][j] = j만큼의 무게를 사용할 수 있고 i번째 보석까지 사용 할 수 있을 때 최대 이득
int max(int x, int y) { return x > y ? x : y; } // x, y 중 큰 값 return
int main() {
    int n, m; // n : 보석의 갯수 // m : 가져갈 수 있는 무게
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= n; ++i) scanf("%d %d", &weight[i], &value[i]); // 무게, 점수 입력
    for(int i = 1; i <= n; ++i) { // 사용할 수 있는 보석 1 ~ i
        for(int j = 1; j <= m; ++j) { // 가져갈 수 있는 무게
            Dp[i][j] = Dp[i - 1][j]; 
            if(j - weight[i] >= 0) Dp[i][j] = max(Dp[i][j], Dp[i - 1][j - weight[i]] + value[i]);
            // 가져갈 수 있는 무게보다 i번째 보석의 무게가 크다면 가져갈 수 없다.
            // Dp[i][j]는 i - 1까지의 보석을 사용했을 경우와 i번째 물건을 가져가는 경우(Dp[i - 1][j - weight[i]] + value[i]) 중 큰 값이다.
        }
    }
    printf("%d", Dp[n][m]); // m만큼의 무게를 모든 보석을 활용하여 가져갈 때 최대 이득을 출력한다.
}
