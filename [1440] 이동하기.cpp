#include <cstdio>
#include <algorithm>
using namespace std;
int candy[1010][1010]; // 각 방에 있는 사탕 수 저장
int DP[1010][1010]; // DP[i][j] = (i, j) 까지 오는데 먹을 수 있는 최대 사탕 수
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) scanf("%d", &candy[i][j]);
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            // (i, j)로 오는 경우는 (i - 1, j)에서 오는 경우나 (i, j - 1)에서 오는 경우다.
            // 즉 (i - 1, j), (i, j - 1)까지 최대로 먹을 수 있는 사탕 수에 현재 방에 있는 사탕 수를 더하면
            // (i, j)까지 오는데 먹을 수 있는 최대 사탕 수를 구할 수 있다.
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) + candy[i][j];
        }
    }
    printf("%d", DP[N][M]); // (1, 1)에서 (N, M)까지 가는데 먹을 수 있는 최대 사탕 수를 출력한다.
}
