#include <iostream>

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << '\n';
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*";
		}
		cout << '\n';
	}*/
	return 0;
}