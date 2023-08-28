#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
int counts;
int p1Score;
int p2Score;
int p1Time;
int p2Time;
deque<int> timestamps;
deque<int> win;
void printNum(int num) {
    string answer = "";
    string temp = to_string(num);
    for (int i = 0; i < 2 - temp.size(); i++) answer += "0";
    cout << answer << temp;
}

int main() {
    cin >> counts;
    for (int i = 0; i < counts; i++) {
        int player; string time;
        cin >> player;
        cin >> time;
        int idx = time.find(":");
        int m = stoi(time.substr(0, idx));
        int s = stoi(time.substr(idx + 1, time.size() - idx - 1));
        timestamps.push_back(m * 60 + s);
        win.push_back(player);
    }
    for (int i = 0; i < 48 * 60; i++) {
        if (timestamps.front() == i) {
            if (win.front() == 1) {
                p1Score++;
            } else {
                p2Score++;
            }
            timestamps.pop_front();
            win.pop_front();
        }
        if (p1Score > p2Score) {
            p1Time++;
        } else if (p1Score < p2Score) {
            p2Time++;
        }
    }
    printNum(p1Time / 60); cout << ":"; printNum(p1Time % 60);
    cout << "\n";
    printNum(p2Time / 60); cout << ":"; printNum(p2Time % 60);
}