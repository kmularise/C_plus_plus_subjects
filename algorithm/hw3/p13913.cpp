#include <iostream>
#include <queue>
using namespace std;
int dist[200002];
int node_next[200002];
int node_prev[200002];
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
    for (int i = 0 ; i < 200002; i++) node_next[i] = -1;
    for (int i = 0 ; i < 200002; i++) node_prev[i] = -1;
    dist[n] = 0;
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
                node_next[current] = next;
                node_prev[next] = current;
            }
        }
    }
    cout << dist[k] << "\n";
    vector<int> answer;
    int i = k;
    int count = 0;
    answer.push_back(i);
    while (node_prev[i] != -1) {
        answer.push_back(node_prev[i]);
        i = node_prev[i];
        count++;
    }
    for (int i = answer.size() -1 ; i >= 0 ; i--) cout << answer[i] << " ";
    cout << "\n";
}