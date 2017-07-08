#include <cstdio>
int DP[1010] = { 1 }; // DP[i] = i의 팰린드롬 파티션 갯수
                      // i 하나로 구성된 팰린드롬 파티션을 구하기 위해 DP[0] = 1로 초기화
int main() {
    for(int i = 1; i <= 1000; ++i) {
        for(int j = i % 2; j <= i; j += 2) {
            DP[i] += DP[(i - j) / 2]; // DP[i] : 중앙에 오는 수가 j일때 팰린드롬 파티션 갯수를 더한다.
            // 팰린드롬이기 때문에 [(i - j) / 2] + j + [(i - j) / 2] 형태로 나오는데 좌우가 대칭이니
            // (i - j) / 2로 만들 수 있는 팰린드롬 파티션의 갯수를 더해준다.
        }
    }
    int t;
    scanf("%d", &t); // 테스트케이스 입력
    while(t--) {
        int tt;
        scanf("%d", &tt);
        printf("%d\n", DP[tt]); // 정답 출력
    }
}
