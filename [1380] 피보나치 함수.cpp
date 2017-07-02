#include <cstdio>
int Dp[2][45], TC; // Dp[0][i] = i번째 fibonacci함수를 호출했을 때 fibo(0)이 호출되는 횟수
                   // Dp[1][i] = i번째 fibonacci함수를 호출했을 때 fibo(1)이 호출되는 횟수
                   // fibo(i)가 return 하는 값은 fibo(i - 1) + fibo(i - 2)이다. (i <= 2)
int main() {
    Dp[0][0] = Dp[0][2] = Dp[1][1] = Dp[1][2] = 1; // Dp배열 초기화
    for(int i = 3; i <= 40; ++i) {
        Dp[0][i] = Dp[0][i - 1] + Dp[0][i - 2]; // i번째 피보나치 함수가 0을 호출하는 횟수는 i - 1과 i - 2가 0을 호출하는 횟수를 합한 것과 같다.
        Dp[1][i] = Dp[1][i - 1] + Dp[1][i - 2]; // i번째 피보나치 함수가 1을 호출하는 횟수는 i - 1과 i - 2가 1을 호출하는 횟수를 합한 것과 같다.
    }
    scanf("%d", &TC); // TESTCASE 갯수 입력
    while(TC--) {
        int n;
        scanf("%d", &n); // n 입력
        printf("%d %d\n", Dp[0][n], Dp[1][n]); // 각각의 n에 대해 0, 1이 호출된 횟수 출력
    }
}
