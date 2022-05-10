#include <iostream>
using namespace std;

int dp[101][101][101] = {};

int w(int a, int b, int c) {
	int da = a + 50, db = b + 50, dc = c + 50;
	if (dp[da][db][dc]) return dp[da][db][dc];

	if (a <= 0 || b <= 0 || c <= 0) {
		dp[da][db][dc] = 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		dp[da][db][dc] = w(20, 20, 20);
	}
	else if (a < b && b < c) {
		dp[da][db][dc] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else dp[da][db][dc] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	
	return dp[da][db][dc];
}

int main() {
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) return 0;
		int result = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
	}
	return 0;
}