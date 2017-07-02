#include <cstdio>
#include <algorithm>
using namespace std;
int coin[101], D[10010], n, k; // D[i] = n가지의 동전들을 사용해서 i원을 만들 때 경우의 수
int main() {
    scanf("%d %d", &n, &k); // n, k 입력
    D[0] = 1; // D[coin[1~n]] 을 처리해주기 위해 초기화
    for(int i = 1; i <= n; ++i) scanf("%d", &coin[i]);
    for(int i = 1; i <= n; ++i) { // i까지의 동전으로 만들 수 있는 경우의 수 체크
        for(int j = 1; j <= k; ++j) { // i까지의 동전으로 k원을 만든다.
            if(j - coin[i] >= 0) D[j] += D[j - coin[i]]; // coin[i]보다 j가 클 경우 j - coin[i]를 만드는 경우의 수를 더해준다.
            // j - coin[i] 를 만드는 경우의 수를 더하는 이유는 j - coin[i]원에다가 coin[i]원을 더하면 j원이 되기 때문이다. 
        }
    }
    printf("%d", D[k]); // k원을 만드는 경우의 수를 출력한다.
}
