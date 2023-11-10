//완전 탐색 
// 총 연산이 30 * 10 = 300 , 300 * 299 * 298 / (1*2*3) 한 4500만정도 나와서 1억 이내라 완전 탐색 가능
// 통과 기준의 경계선에 있어서 방법을 약간 변형함에 따라 통과하지 못하게 되었었다. 이건 어쩔 수 없는 부분이었다..

#include <bits/stdc++.h>
using namespace std;
int n, m, h;
int graph[31][11];
int minVal = 10;

void setGraph(int y, int x) {
    graph[y][x] = 1;
    graph[y][x + 1] = -1;
}

void resetGraph(int y, int x) {
    graph[y][x] = 0;
    graph[y][x + 1] = 0;
}

void print() {
    for (int y = 0 ; y < h ; y++) {
        for (int x = 0; x < n ; x++) {
            cout << graph[y][x] << " ";
        }
        cout << "\n";
    }
}

int isValid() {
    for (int x = 0; x < n ; x++) {
        int pos = x;
        for (int y = 0; y < h; y++) {
            pos += graph[y][pos];
        }
        if (pos != x) {
            return 0;
        }
    }
    return 1;
}

void dfs(int current, int count) {
    if (count == 4 || minVal <= count) {
        return ;
    }
    if (isValid()) {
        minVal = count;
        return ;
    }
    int next = current + 1;
    for (int next = current + 1; next < n * h ; next++) {
        int ny = next / n;
        int nx = next % n;
        if (graph[ny][nx] != 0 || graph[ny][nx + 1] != 0) continue;
        setGraph(ny, nx);
        dfs(next, count + 1);
        resetGraph(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m ; i++) {
        int y, x;
        cin >> y >> x;
        setGraph(y - 1, x - 1);
    }
    dfs(-1, 0);
    cout << (minVal == 10 ? -1 : minVal) << "\n";
}