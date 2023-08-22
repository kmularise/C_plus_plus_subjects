#include <iostream>

using namespace std;

// O(n)
int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long num = 1;
    long long count = 1;
    long long memory_100 = 1;
    for (long long i = 0 ; i < 100 ; i++) {
        memory_100 = (memory_100 * a) % c;
    }
    for (long long i = 0 ; i < b / 100 ; i++) {
        num = (num * memory_100) % c;
    }
    for (long long i = 0 ; i < b % 100 ; i++) {
        num = (num * a) % c;
    }
    cout << num << "\n";
}