#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include <queue>
int n, second, third;
int scv[3];
int dist[61][61][61];

int attack[6][3] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1}
};

typedef struct scvs{
    int first;
    int second;
    int third;
} scvs;

int solve(int first, int second, int third) {
    queue<scvs> q;
    dist[first][second][third] = 0;
    q.push({first, second, third});
    while (!q.empty()) {
        auto ele = q.front();
        q.pop();
        if (dist[0][0][0] != 2147483647)
            break ;
        for (int  i = 0 ; i < 6 ; i++) {
            int next_first = max(ele.first - attack[i][0], 0);
            int next_second = max(ele.second - attack[i][1], 0);
            int next_third = max(ele.third - attack[i][2], 0);
            if (dist[next_first][next_second][next_third] > dist[ele.first][ele.second][ele.third] + 1) {
                dist[next_first][next_second][next_third] = dist[ele.first][ele.second][ele.third] + 1;
                q.push({next_first, next_second, next_third});
            }

        }
    }
    return 0;

}
int main() {
    fill(&dist[0][0][0], &dist[60][60][60], 2147483647);
    cin >> n;
    for (int i = 0 ; i < n; i++){
        cin >> scv[i]; 
    }
    solve(scv[0], scv[1], scv[2]);
    cout << dist[0][0][0] << "\n";
}