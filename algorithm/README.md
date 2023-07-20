# combination
* 재귀, 중첩for문 방식이 있음
* 3개 이하 - 중첩 for문, 4개 이상 - 재귀
* combiantion 재귀로 하는 거 외우기
```cpp
#include <iostream>
#include <vector>
//combination 함수 외우기
using namespace std;

int n = 5, k = 3, numbers[5] = {1, 2, 3, 4, 5};
void print(vector<int> numbers) {
    for (int i : numbers) cout << i << " ";
    cout << '\n';
}

void combi(int start, vector<int> temp) {
    if (temp.size() == k) {
        print(temp);
        return ;
    }
    for (int i = start + 1; i < n; i++) {
        temp.push_back(numbers[i]);
        combi(i, temp);
        temp.pop_back();
    }
}

int main() {
    vector<int> target;
    combi(-1, target);
    return 0;
}
```