#include <iostream>
using namespace std;

#define SIZE 1000001

int one[SIZE] = { 0 };

int main() {
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		one[i] = one[i - 1] + 1;
		if (i % 3 == 0) {
			one[i] = one[i] < (one[i / 3] + 1)? one[i] : (one[i/3]  + 1);
		}
		if (i % 2 == 0) {
			one[i] = one[i] < (one[i / 2] + 1)? one[i] : (one[i/2] + 1);
		}
	}
	cout << one[N];
	return 0;
}