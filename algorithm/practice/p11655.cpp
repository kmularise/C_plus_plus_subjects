#include <iostream>

using namespace std;

int main() {
	string word;
	getline(cin, word);
	for (int i = 0; i <word.size(); i++) {
		if ('A' <= word[i] && word[i] <= 'Z') {
			word[i] = 'A' + (word[i] - 'A' + 13) % 26;
		}
		if ('a' <= word[i] && word[i] <= 'z') {
			word[i] = 'a' + (word[i] - 'a' + 13) % 26;
		}
	}
	cout << word;
}