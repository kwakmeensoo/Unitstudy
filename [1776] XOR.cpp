#include <cstdio>
int solve(int A, int B, int C) { // A, B, C 에 대한 결과를 반환한다.
    if(C % 2) { // 홀수라면
        return A ^ B; // A xor B를 return
    } else { // 짝수라면
        return A; // A를 return
    }
}
int main() {
    int in[3], answer = 0;
    scanf("%d %d %d", in, in + 1, in + 2); // input
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(i == j) continue;
            for(int k = 0; k < 3; ++k) {
                if(k == i || k == j) continue;
                // 각각에 대한 모든 경우를 비교한다.
                answer = answer > solve(in[i], in[j], in[k]) ? answer : solve(in[i], in[j], in[k]);
            }
        }
    }
    printf("%d", answer); // 정답 출력
}
