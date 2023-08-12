#include <iostream>
#include <vector>
using namespace std;
//시간 복잡도 n으로 풀어야 됨, overflow로 long long으로 해야 함
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long	num;
	cin >> num;
	vector<long long> xset;
	vector<long> yset;
	for (int i = 0; i < num ;i ++) {
		long long	x, y;
		cin >> x;
		cin >> y;
		xset.push_back(x);
		yset.push_back(y);
	}
	long long x_total = 0;
	for (long long ele : xset) x_total += ele;
	long long y_total = 0;
	for (int ele: yset) y_total += ele;
	long long total = x_total * y_total;
	for (int i = 0; i < num ; i++) {
		total -= xset[i] * yset[i];
	}
	cout << total << "\n";
}