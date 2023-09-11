#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int parent[50];
int check_count[50];
int answer;

void dfs(int cur, vector<vector<int>> sons , int deleted) {
    if (sons[cur].size() == 0) {
        answer++;
        return;
    }
    int idx = 0;
    for (int next : sons[cur]) {
        if (next == deleted) {
            if (sons[cur].size() == 1) {
                answer++;
                return ;
            }
        }
    }
    for (int next : sons[cur]) {
        if (next == deleted) continue;
        dfs(next, sons, deleted);
    }
}

int getRoot(int x) {
    if (parent[x] == x - 1) {
        return x;
    }
    return getRoot(parent[x]);
}

int main() {
    vector<vector<int>> sons(50);
    cin >> n;
    int root = -1;
    int deleted_target = -1;
    for (int i = 0; i < n; i++) {
        cin >> parent[i];
    }
    // if (parent[0] == -1) {
    //     root = 0;
    // } else {
    //     root = getRoot(0);
    // }
    root = 0;
    for (int i = 0; i < n; i++) {

        if (parent[i] != -1){
            sons[parent[i]].push_back(i);
        } else root = i;

    }
    cin >> deleted_target;
    if (root != deleted_target)
        dfs(root, sons, deleted_target);
    cout << answer;
}