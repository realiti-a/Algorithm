#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int main() {
	int N;
	cin >> N;

	dp = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		dp[i] = 1 + dp[i - 1];
		for (int j = 0; j * j <= i; j++) {
			int square = j * j;
			int other = dp[i - square] + 1;
			dp[i] = other < dp[i] ? other : dp[i];
		}
	}

	cout << dp[N] << "\n";
	return 0;
}