//근처에 있는 애들을 없애는 걸로 함
//visited해서 근처에 있는 애들을 q에 넣어놓음
//만약 도착점에 도달하게 된다면 그때는 종료시킴

#include <iostream>
#include <queue>
using namespace std;
int n, m;
int x1, y1, x2, y2;
char graph[301][301];
int visited[301][301];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

typedef struct point{
    int x;
    int y;
}   point;

void print_graph() {
    cout << "\n";
    for (int y = 0 ; y < n ; y++) {
        for (int x = 0 ; x < m ; x++) {
            cout << graph[y][x];
        }
        cout << "\n";
    }
    // cout << "\n";
}

int main() {
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    for (int y = 0 ; y < n ; y++) {
        string s;
        cin >> s;
        for (int x = 0; x < m ; x++) {
            graph[y][x] = s[x];
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> walls;
    int start_y = y1 - 1;
    int start_x = x1 - 1;
    int end_y = y2 - 1;
    int end_x = x2 - 1;
    int count = 0;
    while(true) {
        q.push({start_y, start_x});
        visited[start_y][start_x] = 1;
        bool isFinished = false;
        while (!q.empty()) {
            auto current = q.front(); q.pop();
            int cy = current.first;
            int cx = current.second;
            for (int i = 0 ; i < 4 ; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (ny < 0 || ny >= n) continue;
                if (nx < 0 || nx >= m) continue;
                if (visited[ny][nx] == 1) continue;
                if (graph[ny][nx] == '#') {
                    isFinished = true;
                    break ;               
                }
                else if (graph[ny][nx] == '1') {
                    walls.push({ny, nx});
                    visited[ny][nx] = 1;
                }
                else if (graph[ny][nx] == '0') {
                    q.push({ny, nx});
                    visited[ny][nx] = 1;
                }
            }
        }
        if (isFinished) break ;
        while (!walls.empty()){
            auto wall = walls.front();
            graph[wall.first][wall.second] = '0';
            walls.pop();
        }
        count++;
        fill_n(&visited[0][0], 301 * 301, 0);
    }
    cout << count + 1 << "\n";
}