#include <cstdio>
#define MOD 1000000000 // 나머지 정의
int square[20] = { 1 }, Dp[1000010][20], N; // 2 ^ 19 < 1000000 < 2 ^ 20
// Dp[i][j] = i를 2 ^ (0 ~ i) 수를 사용해서 만들 수 있는 경우의 수
int solution(int i, int j) {
    //// 기저사례
    if(i < 0) return 0; // N을 못 만드는 경우
    if(i * j == 0) return 1; // i, j 둘중에 하나라도 0일 경우 => N을 만들었거나 j가 0이어서 나머지는 1로만 이루어 졌을 경우
    //// 메모이제이션
    int &ret = Dp[i][j]; // 참조자를 이용한 메모이제이션
    if(ret) return ret; // 한번 계산한 적이 있다면 바로 return
    //// 답 구하기
    return ret = (solution(i, j - 1) + solution(i - square[j], j)) % MOD;
    // i를 2 ^ (1 ~ j - 1)인 수로 나타내는 경우와 2 ^ j 만큼을 빼는 경우로 나누어 계산한다.
}
int main() {
    for(int i = 1; i < 20; ++i) square[i] = square[i - 1] * 2; // 2의 제곱수 구해놓기
    scanf("%d", &N);
    printf("%d", solution(N, 19));
}
