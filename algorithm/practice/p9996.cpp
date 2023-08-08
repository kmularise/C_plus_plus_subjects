#include <iostream>
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
	int n;
	string cmd;
	string word;
	cin >> n;
	cin >> cmd;
	vector<string> pattern = split(cmd, "*");
	for (int i = 0 ; i < n ; i++) {
		cin >> word;
		if (word.size() < pattern[0].size() + pattern[1].size()) {
			cout << "NE" << "\n";
		} else if (word.substr(0, pattern[0].size()).compare(pattern[0]) == 0 
			&& word.substr(word.size() - pattern[1].size(), word.size()).compare(pattern[1]) == 0 ) {
			cout << "DA" << "\n";
		} else {
			cout << "NE" << "\n";
		}
	}
}