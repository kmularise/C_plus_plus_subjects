#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> result;
    long long pos = 0;
    string token = "";
    //while문 외우기
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    result.push_back(input);
    return result;
}

int main() {
    string s = "안녕하세요 여름인데 휴가는 안가세요!?!?? 저는 유럽 가고 싶은데요.", d = " ";
    vector<string> words = split(s, d);
    for (string word : words) cout << word << "\n";
}