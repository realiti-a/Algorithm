#include <iostream>
#include <vector>
using namespace std;

vector<int> stairs;
vector<int> dp;

int N;
void input() {
	cin >> N;
	stairs = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}
	dp = stairs;
}

void upsteps() {
	if (N == 1) return;
	if (N >= 2) dp[2] += dp[1];
	if (N >= 3) {
		for (int i = 3; i <= N; i++) {
			int a = dp[i - 2] + stairs[i];
			int b = dp[i - 3] + stairs[i - 1] + stairs[i];

			dp[i] = a > b ? a : b;
		}
	}
}


int main() {
	input();
	upsteps();

	cout << dp[N] << "\n";
	return 0;
}