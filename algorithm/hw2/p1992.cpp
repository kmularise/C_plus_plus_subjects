#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int n;
int graph[64][64];
int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

vector<int> numbers;
string word = "";
//시간 복잡도  O (n log n) 반씩 줄어들면서 전체 영역 순회 반씩 줄어드는 count는 log n / log 2 이기 때문이다.
void recursive(int plen, int initX, int initY) {
    int len = plen / 2;
    int zeroIdx = 0;
    int oneIdx = 1; 
    for (int y = initY ; y < initY + plen ; y++) {
        for (int x = initX ; x < initX + plen ; x++) {
            zeroIdx += graph[y][x];
            oneIdx *= graph[y][x];
        }
    }
    if (zeroIdx == 0) word += '0';
    else if (oneIdx == 1) word += '1';
    else {
        word += '(';
        for (int idx = 0; idx < 4; idx++){
            int px = initX + len * dx[idx];
            int py = initY + len * dy[idx];
            recursive(len, px, py);
        }
        word += ')';
    }
}

int main() {
    int val;
    cin >> n;
    for (int y = 0; y < n; y++){
        for (int x = 0; x < n; x++) {
            scanf("%1d", &val);
            graph[y][x] = val;
        }
    }
    recursive(n, 0, 0);
    cout << word;
}