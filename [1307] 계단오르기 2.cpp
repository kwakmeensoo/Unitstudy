#include <cstdio>
int stairs[310], Dp[310][2], n;
int mmax(int x, int y) { return x > y ? x : y; } // x, y 중 큰 값 return
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &stairs[i]);
    for(int i = 1; i <= n; ++i) {
        Dp[i][0] = mmax(Dp[i - 2][0], Dp[i - 2][1]) + stairs[i]; // i번째 계단을 연속하지 않고 밟은 경우 2칸전에 최대에 현재 칸을 더한다.
        Dp[i][1] = Dp[i - 1][0] + stairs[i]; // i번째 계단을 연속하여 밟는 경우 i - 1번째 계단을 연속하지 않고 밟은 경우와 현재 칸을 더한다.
    }
    printf("%d", mmax(Dp[n][0], Dp[n][1])); // n번째 계단까지 올라갔을 때 최대값
}