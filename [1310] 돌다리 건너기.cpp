#include <cstdio>
#include <cstring>
char str[30], bridge[2][101];
int D[2][101][30]; // D[i][j][k] = i번째 행의 j번째 칸을 str의 k까지 밟는 경우의 수
int main() {
    scanf("%s %s %s", str + 1, bridge[0] + 1, bridge[1] + 1); // 문자열을 index 1부터 받기 위한 처리
    int len = strlen(str + 1);
    D[0][0][0] = D[1][0][0] = 1; // str의 1번째 문자들을 처리하기 위한 초기화
    for(int i = 1; str[i]; ++i) { // str[i]가 NULL문자가 아닐때까지
        for(int j = 1; bridge[0][j]; ++j) { // bridge[0, 1][i] 가 NULL이 아닐때까지
            for(int k = 0; k < j; ++k) { // j이전의 있는 돌들을 검사한다.
                if(bridge[0][j] == str[i]) D[0][j][i] += D[1][k][i - 1]; // 0번째 행에 있는 값을 구하기 위해선 1번째 행에 있는 str의 i - 1까지 밟는 경우를 참조해야 한다.
                if(bridge[1][j] == str[i]) D[1][j][i] += D[0][k][i - 1]; // 1번째 행에 있는 값을 구하기 위해선 0번째 행에 있는 str의 i - 1까지 밟는 경우를 참조해야 한다.
            }
        }
    }
    int answer = 0; // 정답 변수 초기화
    for(int i = 1; bridge[0][i]; ++i) answer += D[0][i][len] + D[1][i][len]; // str의 끝까지 밟는 경우들을 더한다.
    printf("%d", answer); // 정답 출력
}
