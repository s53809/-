#include <iostream>
#include <vector>

int N, M;
std::vector<int> x;

long long cut(long long H) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (x[i] > H) {
			sum += x[i] - H;
		}
	}
	return sum;
}

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	x.resize(N);
	long long maxNum = 0;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		if (maxNum < x[i]) {
			maxNum = x[i];
		}
	}
	long long start = 0, end = maxNum;
	while (start + 1 < end) {
		long long mid = (start + end) / 2;
		long long sumOfCut = cut(mid);
		if (sumOfCut < M) {
			end = mid;
		}
		else if (sumOfCut >= M) {
			start = mid;
		}
	}
	cout << start;
}