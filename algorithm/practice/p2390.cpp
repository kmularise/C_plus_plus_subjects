#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> selections;

int people[9];
int isDone = 0;

int sum(vector<int> target) {
    int totalSum = 0;
    for (int num : target) {
        totalSum += num;
    }
    return totalSum;
}

void printAnswer(int start) {
    if (selections.size() == 7) {
        if (sum(selections) == 100 && !isDone) {
            isDone = 1;
            sort(selections.begin(), selections.end());
            for (int num : selections) cout << num << '\n';
        }
        return ;
    }
    for (int i = start + 1; i < 9; i++) {
        selections.push_back(people[i]);
        printAnswer(start + 1);
        selections.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0 ; i < 9; i++) {
        cin >> people[i];
    }
    printAnswer(-1);
}