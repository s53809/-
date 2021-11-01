#include <iostream>
#include <string>
#include <vector>

int N;
std::string x;
int strike;
int ball;
int strikeNum;
int ballNum;
std::vector<bool> answer(1000, true);

void isStrike(int j, int q, int k) {
	if (strikeNum != 0) {
		strikeNum--;
	}
	else {
		answer[j * 100 + q * 10 + k] = false;
	}
}

void isBall(int j, int q, int k) {
	if (ballNum != 0) {
		ballNum--;
	}
	else {
		answer[j * 100 + q * 10 + k] = false;
	}
}

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int u = 0; u <= 9; u++) {
				if (i == 0 || j == 0 || u == 0) {
					answer[i * 100 + j * 10 + u] = false;
				}
				if (i == j || i == u || j == u) {
					answer[i * 100 + j * 10 + u] = false;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		cin >> strike;
		cin >> ball;
		bool isAnim = false;
		for (int j = 1; j <= 9; j++) {
			for (int q = 1; q <= 9; q++) {
				for (int k = 1; k <= 9; k++) {
					strikeNum = strike;
					ballNum = ball;
					if (j + '0' == x[0]) {
						isStrike(j, q, k);
					}
					if (q + '0' == x[1]) {
						isStrike(j, q, k);
					}
					if (k + '0' == x[2]) {
						isStrike(j, q, k);
					}
					if (j + '0' == x[1] || j + '0' == x[2]) {
						isBall(j, q, k);
					}
					if (q + '0' == x[0] || q + '0' == x[2]) {
						isBall(j, q, k);
					}
					if (k + '0' == x[0] || k + '0' == x[1]) {
						isBall(j, q, k);
					}
					if (strikeNum != 0) {
						answer[j * 100 + q * 10 + k] = false;
					}
					if (ballNum != 0) {
						answer[j * 100 + q * 10 + k] = false;
					}
				}
			}
		}
	}
	int ansCount = 0;
	for (int i = 111; i < 1000; i++) {
		if (answer[i] == true) {
			ansCount++;
		}
	}
	cout << ansCount;
}