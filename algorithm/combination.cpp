#include <iostream>
#include <vector>
//combination 함수 외우기
using namespace std;

int n = 5, k = 3, numbers[5] = {2, 2, 2, 4, 5};
void print(vector<int> numbers) {
    for (int i : numbers) cout << i << " ";
    cout << '\n';
}

void combi(int start, vector<int> temp) {
    if (temp.size() == k) {
        print(temp);
        return ;
    }
    //인덱스를 기반으로 뽑기 {2, 2, 3, 4, 5} 처럼 중복된 값이 나올 수 있기 때문
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