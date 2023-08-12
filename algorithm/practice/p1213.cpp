#include <iostream>
#include <algorithm> 
#include <string>

using namespace std;

int main() {
    int alphabets[26] = {0};
    string word;
    cin >> word;
    for (char ch : word) {
        alphabets[ch - 'A'] += 1;
    }
    int exist = -1;
    for (int i = 0; i < 26; i++) {
        if (alphabets[i] % 2 != 0) {
            if (exist != -1) {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
            exist = i;
            alphabets[i]--;
        }
    }
    string forward = "";
    string back = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alphabets[i] / 2 ; j++)
            forward.push_back('A' + i);
    }

    cout << forward;
    if (exist != -1) cout << (char) (exist + 'A'); 
    reverse(forward.begin(), forward.end());
    cout << forward << "\n";
}