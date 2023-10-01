#include <iostream>
#include <queue>
using namespace std;
int dist[200002];
int cases[200002];
int n, k;

int getNext(int idx, int current) {
    if (idx == 0) {
        return current - 1;
    }
    if (idx == 1) {
        return current + 1;
    }
    return current * 2;
}

int main() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    for (int i = 0 ; i < 200002; i++) dist[i] = 987654321;
    dist[n] = 0;
    cases[n] = 1;
    while (!q.empty()) {
        int current = q.front();
        if (current == k) {
            break ;
        }
        q.pop();
        for (int i = 0; i < 3; i++) {
            int next = getNext(i, current);
            if (next < 0) continue;
            if (next >= 200002) continue;
            if (dist[next] > dist[current] + 1) {
                dist[next] = dist[current] + 1;
                q.push(next);
                cases[next] = cases[current];
            }
            else if (dist[next] == dist[current] + 1) {
                cases[next]+= cases[current];
            }

        }
    }
    cout << dist[k] << "\n";
    cout << cases[k] << "\n";
}