#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
int n, Path[10010], sz;
bool visited[10010];
queue<int> Q;
void push_value(int here, int next) { // Q에 다음 위치를 넣는 함수
    if(visited[next] || next < 1 || 10000 < next) return;
    Q.push(next); visited[next] = 1; Path[next] = here;
}
int main() {
    scanf("%d", &n);
    push_value(0, 1); // 1에서 시작
    while(!Q.empty()) {
        int h = Q.front();
        Q.pop();
        if(h == n) {
            vector<int> answer;
            while(n) {
                answer.push_back(n); // 현재 위치 저장
                n = Path[n]; // 계속 이전의 왔던 곳으로 이동
            }
            sz = answer.size();
            printf("%d\n", sz - 1); // 과정 출력
            for(int i = 0; i < sz; ++i) printf("%d ", answer[sz - i - 1]); // 경로 출력
            return 0;
        }
        push_value(h, h * 2); // 2배를 늘어난 경우
        push_value(h, h / 3); // 3분의 1이 된 경우
    }
    printf("-1");
    return 0;
}
