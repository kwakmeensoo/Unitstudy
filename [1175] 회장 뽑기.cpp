#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Edge[55]; // 친구관계를 인접리스트로 저장
int N, result[55]; // 각 후보 별로 점수 저장
int main() {
    scanf("%d", &N);
    while(1) {
        int t, tt;
        scanf("%d %d", &t, &tt); // t와 tt는 친구관계
        if(t == -1 && tt == -1) break;
        Edge[t].push_back(tt); // t -> tt
        Edge[tt].push_back(t); // tt -> t
    }
    for(int i = 1; i <= N; ++i) {
        bool visited[55] = { 0 }; // visited 배열
        queue<int> Q;
        Q.push(i);
        visited[i] = 1;
        int temp = 1; // 연결된 회원들 명수
        while(1) {
            if(N == temp) break; // 모든 회원들이 연결되면 종료
            for(int qSize = Q.size(); qSize--;) { // 현재 점수로 연결될 수 있는 회원들
                int here = Q.front();
                Q.pop();
                for(int next = 0; next < Edge[here].size(); ++next) { // i와 here이 친구관계이면 i와 next는 친구의 친구관계
                    if(visited[Edge[here][next]]) continue; // 이미 연결되어있으면 Pass
                    temp++; // 연결된 회원 수 증가
                    visited[Edge[here][next]] = 1; // visit 체크
                    Q.push(Edge[here][next]); // Q에 넣어준다.
                }
            }
            result[i]++; // 이전 점수로 연결할 수 있는 회원들을 연결했으니 점수 증가
        }
    }
    int answer = *min_element(result + 1, result + N + 1); // 가장 작은 점수 반환
    printf("%d\n", answer); // 회장 후보의 점수
    for(int i = 1; i <= N; ++i) {
        if(result[i] == answer) { // 회장 후보의 점수와 이 후보의 점수가 같다면
            printf("%d ", i); // 회장 후보이다.
        }
    }
}
