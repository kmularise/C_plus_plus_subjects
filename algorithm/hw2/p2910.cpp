#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, c;
vector<int> numbers;
map<int, int> counts;
map<int, int> orders;

//시간 복잡도 O(n log n)
bool compare(const int &x, const int &y) {
    // if (counts[x] == counts[y]) {
    //     return orders[x] < orders[y];
    // }
    return counts[x] > counts[y];
}

int main() {
    cin >> n >> c;
    int order = 0;

    int val = -1;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (counts.find(val) == counts.end()) {
            counts[val] = 0;
            orders[val] = order;
            order++;
            numbers.push_back(val);
        }
        counts[val]++;
    }
    stable_sort(numbers.begin(), numbers.end(), compare);
    for (int num : numbers) {
        for (int i = 0; i < counts[num] ; i++) {
            cout << num << " ";
        }
    }
}