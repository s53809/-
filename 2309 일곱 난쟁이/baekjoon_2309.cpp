#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> x;
	x.resize(9);
	int hap = 0;
	for (int i = 0; i < 9; i++) {
		cin >> x[i];
		hap += x[i];
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 9; j++) {
			if (hap - x[i] - x[j] == 100) {
				x[i] = 0;
				x[j] = 0;
				break;
			}
		}
		if (x[i] == 0) break;
	}
	for (int i = 0; i < 9; i++) {
		if (x[i] == 0) continue;
		cout << x[i] << '\n';
	}
}