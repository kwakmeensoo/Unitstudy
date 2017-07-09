#include <cstdio>
int DP[100010][3] = {{}, {1, 1, 1}};
// DP[i][0] = i번째 행에 사자를 배치하지 않는 경우
// DP[i][1] = i번째 행에 왼쪽에 사자를 배치하는 경우
// DP[i][2] = i번째 행에 오른쪽에 사자를 배치하는 경우
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 2; i <= N; ++i) {
        // X X   O X   X O
        // X X   X X   X X
        DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % 9901;
        // X X   X O
        // O X   O X
        DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % 9901;
        // X X   O X
        // X O   X O
        DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % 9901;
    }
    printf("%d", (DP[N][0] + DP[N][1] + DP[N][2]) % 9901);
}
