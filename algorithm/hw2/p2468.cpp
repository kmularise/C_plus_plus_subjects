#include <iostream>
#include <algorithm>
const int max_n = 104;
int n, graph[max_n][max_n], visited[max_n][max_n];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
using namespace std;

void print() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << graph[y][x];
        }
        cout << "\n";
    }
}

void initialize() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            visited[y][x] = 0;
        }
    }
}

void dfs(int cy, int cx, int h) {
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (graph[ny][nx] <= h || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, h);
    }
}

int main() {
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> graph[y][x];
        }
    }
    int max_count = -1;
    int count = 0;
    for (int h = 0 ; h < 101 ; h++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (graph[y][x] <= h || visited[y][x]) continue;
                dfs(y, x, h);
                count++;
            }
        }
        max_count = max(count, max_count);
        count = 0;
        initialize();
    }
    cout << max_count;

}