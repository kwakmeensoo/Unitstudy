#include <cstdio>
#include <cstring> // memset
int Dp[2010][2010]; // Dp[i][j] = arr의 i ~ j까지가 팰린드롬인지 저장
                    // -1 : 미방문 / 0 : 팰린드롬이 아니다 / 1 : 팰린드롬이다
                    // 중복 계산을 방지하기 위해 결과를 저장해 놓는다.
int arr[2010];
int N, M;
int palin(int s, int e) {
    if(s >= e) return 1; // s랑 e가 같거나 s가 e보다 커질때까지 안 걸렸다면 팰린드롬이다.
    int &ret = Dp[s][e]; // ret = Dp[i][j] (참조자 사용)
    if(ret != -1) return ret; // Dp[i][j]가 방문한 적이 있다면 더 들어가지 않고 return
    if(arr[s] != arr[e]) return ret = 0; // arr의 처음과 끝이 다르다면 팰린드롬이 아니다.
    else return ret = palin(s + 1, e - 1); // arr의 처음과 끝이 같다면 s + 1과 e - 1을 비교한다.
}
int main() {
    memset(Dp, -1, sizeof(Dp)); // Dp배열을 -1로 초기화
    scanf("%d", &N); // N 입력
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]); // arr 입력
    }
    scanf("%d", &M); // 질문의 갯수 입력
    for(int i=0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // 홍준이의 질문을 받는다.
        printf("%d\n", palin(a, b)); // 명우의 대답을 출력한다.
    }
}
