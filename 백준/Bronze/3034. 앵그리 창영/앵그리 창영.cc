#include <iostream>
using namespace std;

int N, W, H;
int cross;

int isOkay(int n) {
	if (n * n <= cross) return 1;
	return 0;
}

int main() {
	cin >> N >> W >> H;
	cross = W * W + H * H;

	int fire;
	for (int i = 0; i < N; i++) {
		cin >> fire;

		if (isOkay(fire)) cout << "DA\n";
		else cout << "NE\n";
	}
	return 0;
}