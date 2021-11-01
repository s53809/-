#include <iostream>

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	bool isFind = false;
	for (int i = 0; i < N; i++) {
		int copy_i = i;
		int hap = 0;
		while (copy_i != 0) {
			hap += copy_i % 10;
			copy_i /= 10;
		}
		hap += i;
		if (hap == N) {
			isFind = true;
			cout << i;
			break;
		}
	}
	if (isFind == false) {
		cout << 0;
	}
}