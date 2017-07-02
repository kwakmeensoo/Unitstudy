#include <cstdio>
#define INF 987654321 // 무한대 값 정의
int min(int x, int y) { return x < y ? x : y; }
int D[100010], A[101], N, K; // D[i] = i원을 N가지의 종류의 동전으로 만들 때 최소 갯수
int main() {
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    for(int i = 1; i <= K; ++i) { // 1 ~ K 원
        D[i] = INF; // Dp배열 초기화
        for(int j = 1; j <= N; ++j) {
            if(A[j] > i) continue; // 만약 동전의 값어치가 i원 보다 크면 continue
            D[i] = min(D[i], D[i - A[j]] + 1);
            // D[i]는 1 ~ (j - 1) 까지의 동전을 사용했을 경우와 j번째 동전을 사용한 경우를 비교해 최소값을 넣는다.
            // j번째 동전을 사용한 경우는 (i - 동전[j])원을 이루는 최소 갯수와 j원 짜리 동전 하나가 있으니 D[i - A[j]] + 1(j번째 동전)
        }
    }
    printf("%d", D[K] == INF ? -1 : D[K]); // 만약 K원을 만들 수 없다면 -1 출력, 아니라면 DP배열 출력
}
