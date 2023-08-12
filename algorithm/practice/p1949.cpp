#include <iostream>
#include <vector>
//11:49 시간복잡도 O(n^2) 더 최선의 방법이 있을까?
using namespace std;
int main() {
    int n, m;
    vector<int> numbers;
    cin >> n >> m;
    for (int i = 0 ;i < n; i++) {
        int val;
        cin >> val;
        numbers.push_back(val);
    }
    int count = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] + numbers[j] == m) count++;
        }
    }
    cout << count << "\n";
}