#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int r, c;
const int max_n = 1500;
const int n = 1500 * 1500;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int graph[n];
int visited[n];
int dist[n];
const int INF = 987654321;
vector<int> birds;
queue<int> q;

void print_graph() {
    for (int y = 0 ; y < r ; y++) {
        for (int x = 0 ; x < c ; x++) {
            int target = max_n * y + x;
            cout << dist[target] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void print_visited() {
    for (int y = 0 ; y < r ; y++) {
        for (int x = 0 ; x < c ; x++) {
            int target = max_n * y + x;
            cout << visited[target] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int start) {
    int start_y = start / max_n;
    int start_x = start % max_n;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int cur_y = cur / max_n;
        int cur_x = cur % max_n;
        for (int i = 0 ; i < 4 ; i++) {
            int idx = 0;
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            int next = max_n * next_y + next_x;
            if (next_y < 0 || next_y >= r) continue;
            if (next_x < 0 || next_x >= c) continue;
            if (graph[next] == 'X') idx = 1;
            if (dist[next] > dist[cur] + idx) {
                q.push(next);
                dist[next] = dist[cur] + idx;
            }
        }  
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill_n(&dist[0], n, INF);
    fill_n(&visited[0], n, INF);
    cin >> r >> c;
    for (int y = 0; y < r ; y++)
    {
        string s;
        cin >> s;
        for (int x = 0; x < c; x++) {
            int target = max_n * y + x;
            graph[target] = s[x];
            if (s[x] == 'L') {
                birds.push_back(target);
            }
        }
    }
    int first = birds[0];
    int second = birds[1];
    for (int y = 0 ; y < r ; y++) {
        for (int x = 0 ; x < c ; x++) {
            int target = max_n * y + x;
            if (dist[target] != 0 && graph[target] != 'X') {
                dist[target] = 0;
                bfs(target);
            }
        }
    }
    int count = 0;
    bool isFinished = false;
    q.push(first);
    visited[first] = dist[first];
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == second) {
            isFinished = true;
            break ;
        }
        int curr_y = curr / max_n;
        int curr_x = curr % max_n;
        for (int i = 0; i < 4 ; i++) {
            int next_y = curr_y + dy[i];
            int next_x = curr_x + dx[i];
            int next = next_y * max_n + next_x;
            if (next_y < 0 || next_y >= r) continue;
            if (next_x < 0 || next_x >= c) continue;
            if (visited[next] > max(visited[curr], dist[next])) {
                visited[next] = max(visited[curr], dist[next]);

                q.push(next);
            }
        }            
    }
    cout << visited[second] << "\n";
}