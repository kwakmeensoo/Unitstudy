#include <cstdio>
#include <cstring> // strlen
char str[10101];
// Solution
// 이 문제의 입력은 0 or 1로만 이루어져 있으므로, 00, 11이렇게 붙어있는 경우는
// 팰린드롬이다. 즉 모든 입력은 0과 1이 연속되어 나오지 않는 형태로 바꿀 수 있다.
// 예를 들어 1010101로 압축이 되었다면 중간에 0,1을 추가한다.
// 예 ) 10110101 -> 100101 -> 1001 -> 10
// 즉 처음을 제외한 똑같은 문자가 연속으로 나온 뒤부터는 다 지울수있다.
int main() {
    int A = 1;
    scanf("%s", str); // 문자열 입력
    int l = strlen(str), i = 1; // i초기화
    while(i < l) { //처음 연속된 문자 건너 뛰기
        if(str[i] != str[i - 1]) break; 
        i++;
    }
    for(; i < l; ++i) { // 만약 연속된 문자가 나올 경우 그 뒤는 모두 지울 수 있게된다.
        if(str[i] == str[i - 1]) { // 연속된 문자가 나올 경우 
            printf("%d", A); // 정답을 출력하고 종료
            return 0;
        }
        A++; // 정답 증가(정답 문자열의 길이 증가)
    }
    printf("%d", A); // 연속된 문자를 못찾았을 경우
}