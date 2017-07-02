#include <cstdio>
int D[505][505]; // D[i][j] = 위부터 i행 j열까지 내려올 때 최대 점수
int max(int x, int y) { return x > y ? x : y; } // x, y 중 큰 값 return
int main() {
    int n, answer = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            scanf("%d", &D[i][j]);
            D[i][j] += max(D[i - 1][j], D[i - 1][j - 1]); // (i, j) 로 내려올 수 있는 경우는 두 가지밖에 없는데
            // (i - 1, j)와 (i - 1, j - 1)에서 내려오는 경우이다. D[i][j]는 둘 중 최대 점수가 높은 쪽을 선택하면 된다.
        }
    }
    for(int i = 1; i <= n; ++i) answer = max(answer, D[n][i]); // n번째 행까지 내려온 경우 중 최대값을 찾는다.
    printf("%d", answer); // 답을 출력한다.
}
