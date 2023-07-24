#include <iostream>
using namespace std;
string dopa = "abcde";

int main() {
    cout << dopa.substr(0, 3) << '\n';
    reverse(dopa.begin(), dopa.end());
    cout << dopa << '\n';
    cout << dopa + " umzunsik" << '\n';
    return 0;
}