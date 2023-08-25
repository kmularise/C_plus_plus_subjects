#include <iostream>

using namespace std;
int n;
//nlog n
//ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL); 를 해줘야 됨!
int memory[10];
int unit = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int count = 0;
        int val = num;
        while (val > 0) {
            count += val / 5;
            val = val / 5;
        }
        cout << count << "\n";
    }
}