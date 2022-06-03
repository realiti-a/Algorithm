#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;

	int prevSum = 0, maxSum = -21e8;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;

		prevSum = prevSum + input < input ? input : prevSum + input;
		if (prevSum > maxSum) maxSum = prevSum;
	}

	cout << maxSum << "\n";
	return 0;
}