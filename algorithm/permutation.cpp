#include<bits/stdc++.h>
using namespace std;
int main() {
    //배열 이용시
    int a[] = {1, 2, 3};
    do {
        for (int i : a) cout << i << " ";
        cout << '\n';
    } while (next_permutation(&a[0], &a[0] + 3));
    do {
        for (int i : a) cout << i << " ";
        cout << '\n';
    } while (next_permutation(a, a + 3));
    return 0;
    //vector 이용 시
    vector<int> b = {2, 1, 3, 100, 200};
    sort(b.begin(), b.end());
    do {
        // for (int i : b) cout << i << " ";
        for (int i = 0; i < 2; i++) {
            cout << b[i] << " ";
        }
        cout << '\n';
    } while (next_permutation(b.begin(), b.end()));
    return 0;
}