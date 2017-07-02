#include <cstdio>
#include <cstring> // strlen
char str[1010];
// Solution
// 문자열에 끝에 추가하여 팰린드롬을 만드려면
// i ~ e까지는 팰린드롬이여야 한다. 
// 예를 들어 abab 에서 추가하려면 팰린드롬이 아닌 부분 a와 팰린드롬인 부분 bab에 팰린드롬이 아닌 부분을 끝에 추가하면
// 문자열 전체가 팰린드롬이 된다. 즉 i ~ e까지 가장 긴 팰린드롬에 팰린드롬이 아닌부분을 끝에 추가하면 된다.
int solution(int s, int e) { // s ~ e가 팰린드롬인지 체크하는 함수
    if(s >= e) return 1; // 팰린드롬이라면 1 return
    if(str[s] != str[e]) return 0; // 팰린드롬이 아니라면 0 return
    else return solution(s + 1, e - 1); // str[s]와 str[e]를 검사했다면 str[s + 1]과 str[e - 1]을 검사
}
int main() {
    scanf("%s", &str);
    int len = strlen(str); // len = str의 길이
    for(int i = 0; i < len; ++i) { // i ~ e가 팰린드롬인지 검사한다.
        if(solution(i, len - 1)) { // i ~ e가 팰린드롬이라면
            printf("%d", len + i); // i만큼의 길이가 끝에 추가된 것이니 len + i를 출력한다.
            return 0;
        }
    }
}
