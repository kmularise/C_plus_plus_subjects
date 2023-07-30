#include <iostream>

using namespace std;

int main() {
    int count;
    string word;
    int alphabets[26] = {0};

    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> word;
        alphabets[word[0] - 'a']+= 1;
    }
    bool exist = false;
    for (int i = 0; i < 26; i++) {
        if (alphabets[i] >= 5) {
            cout << static_cast<char>('a' + i);
            exist = true;
        }    
    }
    if (!exist) cout << "PREDAJA";
}