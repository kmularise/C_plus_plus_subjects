#include <iostream>
#include <vector>

using namespace std;

int n;
string s;
vector<int> numbers;
vector<char> operators;
int answer = -987654321;

int calculate(char op, int num1, int num2) {
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
    return -1;
}

void dfs(int idx, int number) {
    if (idx == numbers.size() - 1) {
        answer = max(answer, number);
        return ;
    }
    dfs(idx + 1, calculate(operators[idx], number, numbers[idx + 1]));
    if (idx + 2 <= numbers.size() - 1) {
        int temp = calculate(operators[idx + 1], numbers[idx + 1], numbers[idx + 2]);
        dfs(idx + 2, calculate(operators[idx], number, temp));
    }
    return ;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) numbers.push_back(s[i] - '0');
        else  operators.push_back(s[i]);
    }
    dfs(0, numbers[0]);
    cout << answer;
}

