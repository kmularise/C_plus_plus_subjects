#include <iostream>

using namespace std;
int M, N, J;
//O(n)

int main() {
    cin >> N >> M >> J;
    int pos = 1;
    int apple;
    int dist = 0;
    for (int i = 0; i < J ; i++) {
        cin >> apple;
        if (apple > pos + M - 1) {
            dist += apple - (pos + M - 1);
            pos += apple - (pos + M - 1);
        } else if (apple < pos) {
            dist += pos - apple;
            pos -= pos - apple;
        }
    }

    cout << dist;
    
}