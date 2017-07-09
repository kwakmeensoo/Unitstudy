#include <cstdio>
#include <cmath>
int main() {
    int M, N, A = 0, B = 0; // A = 완전제곱수의 합, B = 가장 작은 완전제곱수
    scanf("%d %d", &M, &N);
    for(int i = M; i <= N; ++i) {
        int ii = int(sqrt(i)); // ii = i의 제곱근에서 소수 부분을 없앤다.
        if(ii * ii == i) { // i의 제곱근이 자연수라면 완전제곱수이다.
            A += i;
            if(B == 0) B = i;
        }
    }
    printf("%d\n%d", A, B); // 정답 출력
}
