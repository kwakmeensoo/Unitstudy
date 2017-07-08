#include <cstdio>
#include <algorithm> // max
using namespace std;
int DP[101][10010]; // i앱까지 j만큼 cost를 썼을 때 최대로 확보할 수 있는 메모리
int memory[101], cost[101], N, M;
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) scanf("%d", &memory[i]);
    for(int i = 1; i <= N; ++i) scanf("%d", &cost[i]);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= 10000; ++j) {
            // DP[i][j] = i번째 앱을 비활성화하지 않는 경우(DP[i - 1][j])와
            //            j번째 앱을 비활성화하는 경우(DP[i - 1][j - cost[i]] + memory[i]) 중 최대값
            // 만약 j - cost[i]가 음수라면 그 경우는 보지 않는다.
            DP[i][j] = max(DP[i - 1][j], j < cost[i] ? 0 : DP[i - 1][j - cost[i]] + memory[i]);
        }
    }
    for(int i = 1; i <= 10000; ++i) {
        if(DP[N][i] >= M) { // i만큼의 cost로 M이상의 메모리를 확보할 수 있다면 정답 출력
            printf("%d", i);
            return 0;
        }
    }
}
