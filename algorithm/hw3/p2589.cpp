#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<char>> graph;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int INF = 2147483647;

int bfs(pair<int, int> start) {
    vector<vector<int>> dist(graph.size(), vector<int>(graph[0].size(), INF));
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n) continue;
            if (nx < 0 || nx >= m) continue;
            if (graph[ny][nx] == 'L' && dist[ny][nx] > dist[cy][cx] + 1) {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }
    int maxVal = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (dist[y][x] != INF) {
                maxVal = max(dist[y][x], maxVal);
            }
        }
    }
    return maxVal;
}

int main() {
    cin >> n >> m;
    for (int y = 0 ; y < n ; y++) {
        vector<char> temp;
        graph.push_back(temp);
        for (int x = 0; x < m; x++) {
            char num;
            cin >> num;
            graph[y].push_back(num);
        }
    }
    int answer = 0;
    for (int i = 0 ; i < n * m; i++) {
        pair<int, int> start = {i / m , i % m};
        if (graph[start.first][start.second] == 'W') continue;
        int rewardDistance = bfs(start);
        answer = max(answer, rewardDistance);
    }
    cout << answer << "\n";

}