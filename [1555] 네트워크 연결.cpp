#include <cstdio>
#include <algorithm>
using namespace std;
int parent[1010], N, M, answer, temp;
int find(int n) { // n번 노드가 속한 그룹을 반환한다.
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}
struct _Edge {
    int cost, x, y; // 정점 x, y와 cost를 저장하는 구조체를 선언한다.
};
bool comp(_Edge a, _Edge b) { return a.cost < b.cost; } // 간선의 비용을 기준으로 정렬한다.
_Edge Edge[100010]; // 간선 배열 선언
int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++i) parent[i] = i; // 가장 처음에는 i는 i그룹에 속한다.
    for(int i = 1; i <= M; ++i) {
        scanf("%d %d %d", &Edge[i].x, &Edge[i].y, &Edge[i].cost);
    }
    sort(Edge + 1, Edge + M + 1, comp); // 간선을 가중치로 정렬한다.
    for(int i = 1; i <= M; ++i) {
        if(find(Edge[i].x) == find(Edge[i].y)) continue; // 만약 x, y가 같은 그룹이라면 continue
        parent[find(Edge[i].x)] = Edge[i].y; // x, y의 그룹을 합친다.
        answer += Edge[i].cost; // 가중치를 더한다.
        temp++; // 연결한 간선 갯수를 증가시킨다.
        if(temp == N - 1) { // 모든 정점이 연결되었다면 종료한다.
            printf("%d", answer); // 정답 출력
            return 0;
        }
    }
}
