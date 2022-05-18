#include <iostream>
using namespace std;

#define MAX 1000000000

int dp[101][10] = {};
int dc[] = { -1, 1 };

int main() {
	int N;
	cin >> N;

	for (int x = 1; x < 10; x++) dp[1][x] = 1;

	for (int y = 1; y < N; y++) {
		for (int x = 0; x < 10; x++) {
			for (int i = 0; i < 2; i++) {
				int dx = x + dc[i];

				if (dx < 0 || dx >= 10) continue;

				dp[y + 1][dx] += dp[y][x];
				dp[y + 1][dx] %= MAX;
			}
		}
	}

	int sum = 0;
	for (int x = 0; x < 10; x++) {
		sum += dp[N][x];
		sum %= MAX;
	}
	cout << sum << "\n";
	return 0;
}