#include <iostream>
using namespace std;

int main() {
    string word;
    cin >> word;
    int mid = word.length() / 2;
    int answer = 1;
    for (int i = 0; i <= mid; i++) {
        if (word[i] != word[word.length() - 1 - i]) answer = 0;
    } 
    cout << answer;
}