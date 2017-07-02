#include <cstdio>
int Dp[400][40]; // 1 <= N <= 39, N이 39일 때 한 집합의 크기는 390이다.
                 // Dp[i][j] = i를 j까지 수로 나타내는 경우의 수
int main() {
    int n;
    scanf("%d", &n);
    int size = (n * n + n) / 2; // 1 ~ N 합
    if(size % 2) { // 만약 두 집합으로 나눌 수 없는 경우
        printf("0"); // 방법이 없는 경우
        return 0; // 프로그램 종료
    }
    Dp[0][0] = 1; // Dp[1][1]에서 참조할 수 있도록 초기화
    for(int i = 1; i <= size / 2; ++i) { // 두 집합으로 나눴을 때 한 집합의 크기는 size / 2 이다
        for(int j = 1; j <= n; ++j) { // 1 ~ n까지 사용
            Dp[i][j] = Dp[i][j - 1]; // j - 1까지 사용 했을 때 +
            if(i - j >= 0) Dp[i][j] += Dp[i - j][j - 1]; // j를 사용하여 나타내는 경우
        }
    }
    printf("%d", Dp[size / 2][n]); // n까지 사용 했을 때 경우의 수 출력
}
