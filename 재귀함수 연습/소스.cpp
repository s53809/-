#include <iostream>

char str[100];

void Func(int N) {
	if (N < 0) return;
	std::cout << str[N];
	Func(N - 1);
}

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	for (int i = 0; i < 100; i++) {
		if (str[i] == NULL) {
			Func(i - 1);
			break;
		}
	}
}