#include<iostream>
using namespace std;

long long int Func(long long int a, long long int b, long long int c) {
	if (b == 1) {
		return a % c;
	}
	long long int temp = Func(a, b / 2, c);
	if (b % 2 == 0) {
		return temp * temp % c;
	}
	else {
		return (temp * temp) % c * a % c;
	}
}

long long mulply(long a, long b, long c) {
	long long result = 1;
	while (b > 0) {
		if (b % 2) {
			result = (result * a) % c;
		}
		a *= a % c;
		a %= c;
		b /= 2;
	}
	return result;
}

int main() {
	long long int a, b, c;
	cin >> a >> b >> c;
	cout << mulply(a, b, c);
	return 0;
}