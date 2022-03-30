#include <iostream>
using namespace std;

int getSet(int n) {
	int dat[10] = {};
	while (n) {
		dat[n % 10]++;
		n /= 10;
	}
	int max = 0;

	dat[6] += dat[9];

	if (dat[6] % 2) dat[6] = dat[6] / 2 + 1;
	else dat[6] /= 2;
	dat[9] = dat[6];

	for (int i = 0; i < 10; i++) {
		if (dat[i] > max) max = dat[i];
	}
	
	return max;
}

int main() {
	int N;
	cin >> N;
	cout << getSet(N) << "\n";
	return 0;
}