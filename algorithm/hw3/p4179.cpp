#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int INF = 2147483647;
int mintime = 2147483647;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isEnd(int cy, int cx, vector<string> graph) {
    if (graph[cy][cx] != '.') return false;
    if (cy == 0 || cy == n - 1) return true;
    if (cx == 0 || cx == m - 1) return true;
    return false;
}

void print(vector<string> graph) {
    for (int y = 0; y < n; y++) {
        cout << graph[y] << "\n";
    }
}

void print_vectors(vector<vector<int>> dist) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << dist[y][x] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<string> graph;
    queue<pair<int, int>> q;
    int start_y;
    int start_x;
    cin >> n >> m;
    vector<vector<int>> fire_dist(n, vector<int>(m, INF));
    vector<vector<int>> player_dist(n, vector<int>(m, INF));
    for (int y = 0 ; y < n; y++) {
        string temp;
        cin >> temp;
        graph.push_back(temp);
    }

    for (int y = 0 ; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (graph[y][x] == 'F') {
                q.push({y, x});
                fire_dist[y][x] = 0;
            }
            if (graph[y][x] == 'J') {
                player_dist[y][x] = 0;
                start_y = y;
                start_x = x;
            }
        }
    }
    int minVal = INF;

    //fire bfs
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n) continue;
            if (nx < 0 || nx >= m) continue;
            if (graph[ny][nx] == '#') continue;
            if (fire_dist[ny][nx] > fire_dist[cy][cx] + 1) {
                fire_dist[ny][nx] = fire_dist[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }
    // print_vectors(fire_dist);
    q.push({start_y, start_x});
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        if (cy == 0 || cy == n - 1 || cx == 0 || cx == m - 1) {
            minVal = min(minVal, player_dist[cy][cx] + 1);
            break ;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n) continue;
            if (nx < 0 || nx >= m) continue;
            if (graph[ny][nx] == '#') continue;
            if (fire_dist[ny][nx] <= player_dist[cy][cx] + 1) continue;
            if (player_dist[ny][nx] > player_dist[cy][cx] + 1) {
                player_dist[ny][nx] = player_dist[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }

    // print_vectors(player_dist);
    if (minVal == INF) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        cout << minVal << "\n";
    }
}