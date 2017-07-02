#include <cstdio>
int Dp[100010]; // 1 <= N <= 100000
int mmin(int x, int y) { return x < y ? x : y; } // x, y가 들어올 때 작은 값을 return
int main() {
    int N;
    scanf("%d", &N); // N 입력
    for(int i = 1; i <= N; i++) {
        Dp[i] = 987654321; // Dp 배열 무한대로 초기화
        for(int j = 1; j * j <= i; j++) {
            Dp[i] = mmin(Dp[i], Dp[i - j * j] + 1); // Dp[i]에 저장 되어있는 값과
            // j ^ 2 + (i - j ^ 2) 경우 j ^ 2은 하나의 제곱수이니 Dp[i - j ^ 2] + 1과 비교해서 최소를 넣는다.
        }
    }
    printf("%d", Dp[N]); // N을 제곱수의 합으로 나타냈을 때 최소 갯수를 출력한다.
}