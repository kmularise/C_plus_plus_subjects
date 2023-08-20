#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, graph[101][101], visited[101][101];
int blx, bly, urx, ury;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ret;
vector<int> rets;

void dfs(int cy, int cx) {
    ret += 1;
    visited[cy][cx] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!graph[ny][nx] || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

void print() {
    for (int y = m - 1 ; y >= 0 ; y--) {
        for (int x = 0; x < n; x++) {
            cout << visited[y][x];
        }
        cout << "\n";
    }
}
void show() {
    for (int y = m - 1 ; y >= 0 ; y--) {
        for (int x = 0; x < n; x++) {
            cout << graph[y][x];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    fill(&graph[0][0], &graph[0][0] + 101 * 101, 1);
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> blx >> bly >> urx >> ury;
        for (int y = bly; y < ury; y++){
            for (int x = blx ; x < urx ; x++) {
                if (y < 0 || y >= m || x < 0 || x >= n) continue;
                graph[y][x] = 0;
            }
        }
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = m - 1 ; y >= 0 ; y--) {
            if (graph[y][x] && !visited[y][x]) {
                ret = 0;
                dfs(y, x);
                rets.push_back(ret);
                answer += 1;
            }
        }
    }
    sort(rets.begin(), rets.end());
    cout << answer << "\n";
    for (int ele : rets) {
        cout << ele << " ";
    }

}