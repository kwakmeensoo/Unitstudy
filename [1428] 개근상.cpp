#include <cstdio>
#define MOD 1000000 // 나머지 정의
int N, D[1010][2][3]; // D[i][j][k] = i일까지 j번 지각했고 k번 연속으로 결석했을 때 개근상을 받을 수 있는 경우의 수
int solution(int i, int j, int k) {
    if(j == 2 || k == 3) return 0; // 지각이 2번이거나 3번 연속으로 결석한 경우
    if(i == N) return 1; // N일 까지 출석한 경우
    int &ret = D[i][j][k]; // 참조자를 이용해 메모이제이션
    if(ret) return ret; // 이전에 계산을 한 경우라면 바로 return
    return ret = ( solution(i + 1, j, 0)             // 출석하는 경우
                 + solution(i + 1, j + 1, 0)         // 지각하는 경우
                 + solution(i + 1, j, k + 1)) % MOD; // 결석하는 경우
}
int main() {
    scanf("%d", &N);
    printf("%d", solution(0, 0, 0)); // N일 까지 출석할 수 있는 경우의 수를 출력한다.
}
