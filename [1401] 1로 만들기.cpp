#include <cstdio>
int Dp[1000100]; // Dp배열 선언
int mmin(int x, int y) { return x < y ? x : y; } // x, y 중 작은 값을 return
int main() {
    int n;
    scanf("%d", &n); // n입력
    for(int i = 2; i <= n; i++) { // 2부터 시작해서 n까지 1로 만드는 최솟값을 구한다.
        Dp[i] = Dp[i - 1] + 1; // 1을 빼는 경우
        if(i % 3 == 0) Dp[i] = mmin(Dp[i / 3] + 1, Dp[i]); // 3으로 나눌 수 있는 경우, 1을 뺀 경우와 비교해서 min값을 넣어준다.
        if(i % 2 == 0) Dp[i] = mmin(Dp[i / 2] + 1, Dp[i]); // 2로 나눌 수 있는 경우, 3으로 나눈 경우와 1을 뺀 경우와 비교해서 min값을 넣어준다.
    }
    printf("%d", Dp[n]); // n에서 1로 가는 방법의 최솟값을 출력한다.
}