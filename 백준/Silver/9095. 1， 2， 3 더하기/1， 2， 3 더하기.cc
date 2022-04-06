#include <iostream>
using namespace std;

int cnt;
int N;
int sum;
void makeN() {
	if (sum == N) {
		cnt++;
		return;
	}
	else if (sum > N) {
		return;
	}
	else {
		for (int i = 1; i <= 3; i++) {
			sum += i;
			makeN();
			sum -= i;
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		cnt = 0, sum = 0;
		makeN();
		cout << cnt << "\n";
	}
	return 0;
}