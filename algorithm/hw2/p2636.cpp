#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int INF = 2147483647;
int graph[100][100];
int dist[100][100];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

void bfs(int iy, int ix) {
    q.push(make_pair(iy, ix));
    while (!q.empty()) {
        int cy;
        int cx;
        tie(cy, cx) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n) continue;
            if (nx < 0 || nx >= m) continue;
            if (dist[ny][nx] > dist[cy][cx] + graph[ny][nx]) {
                dist[ny][nx] = dist[cy][cx] + graph[ny][nx];
                q.push(make_pair(ny, nx));
            }
        }
    }
}

void print() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << dist[y][x] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> graph[y][x]; 
            dist[y][x] = INF;
        }
    }
    //가장자리 파악하기
    for (int y = 0; y < n; y+=(n - 1)) {
        for (int x = 0; x < m; x++) {
            if (dist[y][x] > graph[y][x]) {
                dist[y][x] = graph[y][x];
                bfs(y, x);
            }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x+=(m - 1)) {
            if (dist[y][x] > graph[y][x]) {
                dist[y][x] = graph[y][x];
                bfs(y, x);
            }
        }
    }
    int maxVal = -1;
    int count = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (graph[y][x] == 1) {
                if (dist[y][x] > maxVal) {
                    maxVal = dist[y][x];
                    count = 0;
                }
                if (dist[y][x] == maxVal) count++;
            }
        }
    }
    cout << maxVal << "\n";
    cout << count << "\n";
}