#include <cstdio>
int D[210][210]; // Dp배열 선언
int mmax(int x, int y) { return x > y ? x : y; } // x, y 중 큰 값을 return
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) scanf("%d", &D[i][j]);
    for(int i = n - 1; i >= 0; --i) { // 맵의 가장 아랫줄부터 윗줄까지
        for(int j = n - 1; j >= 0; --j) { // 오른쪽열 부터 왼쪽열로
            D[i][j] += mmax(D[i + 1][j], D[i][j + 1]); // 자기의 오른쪽 칸과 아랫쪽 칸을 비교해서 큰값 저장 
        }
    }
    printf("%d", D[0][0]); // (0, 0) 에서 시작했을 때 최대 미네랄 양 출력
}