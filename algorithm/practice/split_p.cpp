#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main() {
    string s = "I love you. Do you love me?", d = " ";
    vector<string> words = split(s, d);
    for (string word : words) cout << word << "\n";
}
