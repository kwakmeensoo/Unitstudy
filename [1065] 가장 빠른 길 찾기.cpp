#include <queue>
#include <cstdio>
#include <utility>
using namespace std;
typedef pair<int, int> info;
queue<info> Q;
int n, m, answer = 1;
bool visited[101][101];
int dirx[4] = { 0, 0, -1, 1};
int diry[4] = { 1, -1, 0, 0};
void push_value(int nx, int ny) { // Q에 다음 위치를 넣어준다.
    if(nx == 0 || ny == 0 || nx > n || ny > m || visited[nx][ny]) return;
    visited[nx][ny] = 1; Q.push({nx, ny});
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) scanf("%1d", &visited[i][j]);
    }
    push_value(n, 1); // (n, 1) 에서 시작
    while(!Q.empty()) {
        int qs = Q.size();
        while(qs--) {
            int hx = Q.front().first;
            int hy = Q.front().second;
            Q.pop();
            if(hx == 1 && hy == m) { // (1, m) 에서 종료
                printf("%d", answer);
                return 0;
            }
            for(int i = 0; i < 4; ++i) push_value(hx + dirx[i], hy + diry[i]); // 상, 하, 좌, 우를 넣어준다.
        }
        answer++; // 정답 증가
    }
    printf("-1"); // 불가능한 경우 처리
    return 0;
}
