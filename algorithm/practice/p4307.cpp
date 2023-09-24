#include <iostream>

using namespace std;
int t, n, l;

int main() {
    cin >> t;
    for (int i = 0 ; i < t; i++) {
        cin >> l >> n;
        int left_time = 0;
        int right_time = 0;
        for (int j = 0 ; j < n ; j++) {
            int val;
            cin >> val;
            int min_time = min(val, l - val);
            int max_time = max(val, l - val);
            left_time = max(min_time, left_time);
            right_time = max(right_time, max_time);
        }
        cout << left_time << " " << right_time << "\n";
    }
}