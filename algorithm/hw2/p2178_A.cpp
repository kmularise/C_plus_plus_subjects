// #include <iostream>
// #include <queue>
#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int n, m, graph[max_n][max_n], visited[max_n][max_n], cy, cx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int n, m;
    scanf("%d %d", &n, &m);
    for (int y = 0 ; y < n; y++) {
        for (int x = 0 ; x < m; x++) {
            scanf("%1d", &graph[y][x]);
        }
    }
    //bfs
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        tie(cy, cx) = q.front();
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n) continue;
            if (nx < 0 || nx >= m) continue;
            if (!graph[ny][nx]) continue; 
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
    cout << visited[n - 1][m - 1] << "\n";
}