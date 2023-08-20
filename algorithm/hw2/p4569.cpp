#include <iostream>

using namespace std;

bool isAEIOU[26];
char AEIOU[5] = {'a', 'e', 'i', 'o', 'u'}; 
bool triple[3];

string isAcceptable(string word) {
    bool hasAEIOU = false;

    for (int i = 0; i < word.size() ; i++) {
        if (isAEIOU[word[i] - 'a']) {
            hasAEIOU = true;
        }
        if (i < 1) continue;
        if (word[i] != 'e' && word[i] != 'o' &&
            word[i] == word[i - 1]) {
            return "not acceptable";
        }
        if (i < 2) continue;
        for (int j = 0; j < 3; j++) {
            triple[j] = isAEIOU[word[i - j] - 'a'];
        }
        if (triple[0] &&  triple[1] && triple[2]) {
            return "not acceptable";
        }
        if (!triple[0] &&  !triple[1] && !triple[2]) {
            return "not acceptable";
        }
    }
    if (!hasAEIOU) return "not acceptable";
    return "acceptable";
}

int main() {
    string word;
    
    for (char ele : AEIOU) {
        isAEIOU[ele - 'a'] = true;
    }
    while (1) {
        cin >> word;
        if (word.compare("end") == 0) {
            return 0;
        }
        cout << "<" << word << ">" << " is " << isAcceptable(word) << ".\n";
    }
}