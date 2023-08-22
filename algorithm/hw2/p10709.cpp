#include <iostream>

using namespace std;

string graph[100];
int arrays[100][100];

int h, w;
int main() {
    cin >> h >> w;
    for (int y = 0; y < h; y++) {
        cin >> graph[y];
    }

    for (int y = 0; y < h; y++) {
        int answer = -1;
        for (int x = 0; x < w; x++) {
            int pos = x;
            while (pos >= 0) {
                if (graph[y][pos] == 'c') {
                    answer = x - pos;
                    break ;
                }
                pos--;
            }
            arrays[y][x] = answer;
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cout << arrays[y][x] << " ";
        }
        cout << "\n";
    }
}