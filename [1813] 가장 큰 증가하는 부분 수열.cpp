#include <cstdio>
#include <algorithm> // max, max_element
using namespace std;
int A[1010], D[1010], N; // D[i] = i를 끝으로 하는 합이 가장 큰 증가 부분 수열
int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j < i; ++j) {
        	// D[i] = j뒤에 i를 이어 붙인다고 할 때 j까지 합과 i를 더한다.
            if(A[j] < A[i]) D[i] = max(D[i], D[j] + A[i]);
        }
    }
    printf("%d", *max_element(D + 1, D + N + 1)); // 1 ~ N을 끝으로 하는 증가 부분 수열 중 가장 큰 값을 출력한다.
}
