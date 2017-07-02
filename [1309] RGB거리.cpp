#include <cstdio>
int Dp[1010][3]; // Dp[i][j] = (i번째 집까지 색칠하고 i번째 집이 R, G, B색일때 최소)
int min(int x, int y) { return x < y ? x : y; } // x, y중 작은값 return
int main() {
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		for(int j = 0; j < 3; ++j) scanf("%d", &Dp[i][j]); // 각각 집을 R, G, B로 칠하는 비용 입력
	for(int i = 1; i <= N; ++i) {
		Dp[i][0] += min(Dp[i - 1][1], Dp[i - 1][2]); // i번째 집을 R로 칠할 경우, i - 1번째 집의 G, B로 칠한 경우 + R로 칠하는 비용
		Dp[i][1] += min(Dp[i - 1][0], Dp[i - 1][2]); // i번째 집을 G로 칠할 경우, i - 1번째 집의 R, B로 칠한 경우 + G로 칠하는 비용
		Dp[i][2] += min(Dp[i - 1][0], Dp[i - 1][1]); // i번째 집을 B로 칠할 경우, i - 1번째 집의 R, G로 칠한 경우 + B로 칠하는 비용
	}
	printf("%d", min(min(Dp[N][0], Dp[N][1]), Dp[N][2])); // N번째 집을 칠한 경우 중 최소값을 출력
}