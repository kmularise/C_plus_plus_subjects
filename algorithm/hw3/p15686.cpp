#include <iostream>
#include <vector>
using namespace std;
int n, m;
int graph[51][51];
vector<pair<int, int>> homes;
int minVal = 2147483647;

int getDistance(pair<int, int> home, pair<int, int> store) {
    return abs(home.first - store.first) + abs(home.second - store.second);
}

int getMin(pair<int, int> home, vector<pair<int, int>> candidates)
{
    int dist = 2147483647;
    for (pair<int, int> candidate : candidates) {
        dist = min(dist, getDistance(home, candidate));
        // int temp = getDistance(home, candidate);
        // if (temp < dist) dist = temp;
    }
    return dist;
}

int getChickenDistance(vector<pair<int, int>> candidates)
{
    int total = 0;
    for (pair<int, int> home : homes) {
        total += getMin(home, candidates);
    }
    return total;
}

void dfs(vector<pair<int, int>> stores, vector<pair<int, int>> candidates, int idx) {
    // cout << candidates.size() << "\n";
    // for (auto candidate : candidates) cout << candidate.first << "," << candidate.second << " ";
    // cout << "\n";
    if (candidates.size() == m) {
        minVal = min(minVal, getChickenDistance(candidates));
        return ;
    }
    for (int i = idx + 1; i < stores.size() ; i++) {
        candidates.push_back(stores[i]);
        dfs(stores, candidates, i);
        candidates.pop_back();
    }

}

int main() {
    vector<pair<int, int>> stores;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (graph[y][x] == 1) {
                homes.push_back(make_pair(y, x));
            }
            if (graph[y][x] == 2) {
                stores.push_back(make_pair(y, x));
            }
        }
    }
    vector<pair<int, int>> candidates;
    dfs(stores, candidates, -1);
    cout << minVal << "\n";
}