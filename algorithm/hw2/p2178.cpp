#include <iostream>
#include <queue>
using namespace std;

int count = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;
    int graph[n][m];
    int visited[n][m];

    for (int y = 0 ; y < n; y++) {
        string temp;
        cin >> temp;
        for (int x = 0 ; x < m; x++) {
            graph[y][x] = temp[x] - '0';
            visited[y][x] = 0;
        }
    }
    //bfs
    queue<int> q_y;
    queue<int> q_x;
    visited[0][0] = 1;
    q_y.push(0);
    q_x.push(0);
    while (!q_y.empty()) {
        int cy = q_y.front();
        int cx = q_x.front();
        q_y.pop();
        q_x.pop();
        for (int i = 0 ; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n) continue;
            if (nx < 0 || nx >= m) continue;
            if (!graph[ny][nx]) continue; 
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q_y.push(ny);
            q_x.push(nx);
        }
    }
    cout << visited[n - 1][m - 1] << "\n";
}