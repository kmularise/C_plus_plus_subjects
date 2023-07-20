
#include <iostream>
using namespace std;
int numbers[3] = {1, 2, 3};
int n = 3, r = 3;

void print() {
    for (int i = 0 ; i < r ; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";
}

void makePermutation(int n, int r, int depth) {
    if (r == depth) {
        print();
        return ;
    }
    for (int i = depth; i < n; i++) {
        cout<<i<<":"<<depth<<"를 바꾼다!\n";
        swap(numbers[i], numbers[depth]);
        makePermutation(n, r, depth + 1);
        cout<<i<<":"<<depth<<"를 다시 바꾼다!\n";
        swap(numbers[i], numbers[depth]);
    }
    return ;
}

int main() {
    makePermutation(n, r, 0);
    cout << "\n";
}

