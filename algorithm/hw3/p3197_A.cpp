#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int max_n = 1501;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int r, c;
int swanY, swanX;
string s;
int swan[max_n][max_n], visited[max_n][max_n];
char graph[max_n][max_n];
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;

void queue_clear(queue<pair<int, int>> &q) {
    queue<pair<int, int>> empty;
    swap(q, empty);
}

void water_melting() {
    int cy, cx;
    while(waterQ.size()) {
        tie(cy, cx) = waterQ.front();
        waterQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) {
                continue;
            }
            if (graph[ny][nx] == 'X') {
                visited[ny][nx] = 1;
                water_tempQ.push({ny, nx});
                graph[ny][nx] = '.';
            }
        }
    }
}

bool move_swan() {
    int cy, cx;
    while (swanQ.size()) {
        tie(cy, cx) = swanQ.front();
        swanQ.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c ||
                swan[ny][nx]) continue;
            swan[ny][nx] = 1;
            if (graph[ny][nx] == '.') swanQ.push({ny, nx});
            else if (graph[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            else if (graph[ny][nx] == 'L') return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for (int y = 0; y < r; y++) {
        cin >> s;
        for (int x = 0; x < c; x++) {
            graph[y][x] = s[x];
            if (graph[y][x] == 'L') {
                swanY = y; swanX = x;
            }
            if (graph[y][x] == '.' || graph[y][x] == 'L') {
                visited[y][x] = 1;
                waterQ.push({y, x});
            }
        }
    }
    swanQ.push({swanY, swanX});
    swan[swanY][swanX] = 1;
    int day = 0;
    while (true) {
        if (move_swan()) break;
        water_melting();
        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        queue_clear(water_tempQ);
        queue_clear(swan_tempQ);
        day++;
    }
    cout << day << "\n";
}