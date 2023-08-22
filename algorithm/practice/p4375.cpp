#include <iostream>
using namespace std;
//시간 복잡도 N
int main() {
    long long N;
    while(cin >> N) {
        long long factor = 1;
        long long count = 1;
        if (N % 10 == 0) continue ;
        long long initialVal = 0;
        while (1)
        {
            initialVal = (initialVal + factor) % N;
            if (initialVal == 0) break ;
            factor = (factor * 10) % N;
            count++;
        }
        cout << count << "\n";
    }
}