#include <cstdio>
int DP[202][202]; // DP[i][j] = i개의 숫자를 이용해서 j를 만드는 경우의 수
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    DP[0][0] = 1; // DP[1][i]인 경우에서 참조
    for(int i = 1; i <= K; ++i) {
        for(int j = 0; j <= N; ++j) {
            for(int k = 0; k <= j; ++k) {
                DP[i][j] += DP[i - 1][k];
                // DP[i][j] = i - 1개의 숫자를 이용해서 k를 만든 경우에다가 
                //(j - k)를 더하면 i개의 숫자로 j를 만드는 경우의 수가 된다.
                DP[i][j] %= 1000000000;
            }
        }
    }
    printf("%d", DP[K][N] % 1000000000); // N을 K개의 숫자로 만드는 경우의 수 출력
}
