# include <iostream>
# include <queue>
using namespace std;
int n, l, r;
int graph[51][51];
int INF = 2147483647;
int dist[51][51] = {INF, };
int visited[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> candidates;
    q.push({y, x});
    dist[y][x] = 0;
    int count = 0;
    int total = 0;
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        candidates.push_back({cy, cx});
        q.pop();
        count++;
        total += graph[cy][cx];
        
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n) continue;
            if (nx < 0 || nx >= n) continue;
            if (visited[ny][nx] == 1) continue;
            int statement = abs(graph[ny][nx] - graph[cy][cx]);
            if (statement >= l && statement <= r && dist[ny][nx] > dist[cy][cx] + 1) {
                q.push({ny, nx});
                dist[ny][nx] = dist[cy][cx] + 1;
            }
        }
    }
    for (auto ele : candidates) {
        graph[ele.first][ele.second] = total / count ;
        visited[ele.first][ele.second] = 1;
    }
    return count;
}
void print() {
    cout << "\n";
    for (int y = 0 ; y < n; y++) {
        for (int x = 0; x < n ; x++) {
            cout << graph[y][x] << " ";
        }
        cout << "\n";
    }
    // cout <<"\n";
}

int main() {
    cin >> n >> l >> r;
    for (int y = 0 ; y < n; y++) {
        for (int x = 0; x < n ; x++) {
            cin >> graph[y][x];
        }
    }
    int end_idx = 0;
    int day = 0;
    while (true) {
        end_idx = 1;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x< n; x++) {
                dist[y][x] = INF;
                visited[y][x] = 0;
            }
        }
        for (int y = 0 ; y < n; y++) {
            for (int x = 0; x < n ; x++) {
                if (dist[y][x] < INF) continue;
                int count = bfs(y, x);
                if (count != 1) end_idx = 0;
            }
        }
        if (end_idx) break ;
        day++;
    }
    cout << day << "\n";
}