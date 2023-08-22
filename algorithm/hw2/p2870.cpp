#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
//시간 복잡도 O(n^2)
using namespace std;

int n;
vector<string> numbers;
string word;
string number1;

bool compare(string x, string y) {
    if (x.size() == y.size()) {
        return x.compare(y) < 0;
    }
    return x.size() < y.size();
}

string getZeroRemovedNumber(string number) {
    int npos = number.find_first_not_of('0');
    if (npos == -1) {
        return "0";
    }
    number.erase(0, npos);
    return number;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        for (char ch : word) {
            if ('0' <= ch && ch <= '9') {
                number1+= ch;
            } 
            else if (number1.compare("") != 0) {
                numbers.push_back(getZeroRemovedNumber(number1));
                number1 = "";
            }
        }
        if (number1.compare("") != 0) {
            numbers.push_back(getZeroRemovedNumber(number1));
            number1 = "";
        }
    }
    sort(numbers.begin(), numbers.end(), compare);
    for (string number : numbers) cout << number << "\n";
}