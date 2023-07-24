#include <iostream>
using namespace std;

int numbers[100004], n, m, a, b, psum[100004];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    numbers[0] = 0;
    psum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
        psum[i] = psum[i - 1] + numbers[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << psum[b] - psum[a - 1] << '\n';
    }
}