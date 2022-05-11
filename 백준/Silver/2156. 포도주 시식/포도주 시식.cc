#include <iostream>
using namespace std;

int wine[10002] = {};
int dp[10002] = {};

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> wine[i];
	dp[1] = wine[1], dp[2] = wine[1] + wine[2];

	int tmp = dp[2];
	for (int i = 3; i <= N; i++) {
		int a = dp[i - 3] + wine[i - 1] + wine[i];
		int b = dp[i - 2] + wine[i];
		int c = dp[i - 1];
		
		dp[i] = a > b ? a : b;
		if (c > dp[i]) dp[i] = c;
	}

	int maxValue = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i] > maxValue) maxValue = dp[i];
	}

	cout << maxValue << "\n";
	return 0;
}