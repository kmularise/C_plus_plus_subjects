#include <iostream>
using namespace std;
int main() {
    int alphabets[26] = {0};
    string word;
    string::iterator it;

    cin >> word;
    for (it = word.begin() ; it != word.end(); it++) {
        alphabets[*it - 'a'] += 1;
    }
    for (int count : alphabets) {
        cout << count << ' ';
    }
}