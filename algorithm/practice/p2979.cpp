#include <iostream>
using namespace std;
int a, b, c, start, last;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int change[101] = {0};
    int fee[4];
    cin >> a >> b >> c;
    fee[0] = 0;
    fee[1] = a;
    fee[2] = b;
    fee[3] = c;
    for (int i = 0; i < 3; i++) {
        cin >> start >> last;
        change[start] += 1;
        change[last] -= 1;
    }
    int count = 0;
    int total = 0;
    for (int i = 1; i <= 100; i++) {
        count += change[i];
        total += fee[count] * count;
    }
    cout << total << '\n';
}