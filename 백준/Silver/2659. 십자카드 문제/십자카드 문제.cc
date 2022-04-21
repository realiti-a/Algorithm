#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int card[4] = {};
vector<int> res;
void input() {
	for (int i = 0; i < 4; i++) {
		cin >> card[i];
	}
}

int getClock(int *c) {
	int min = 21e8;
	for (int i = 0; i < 4; i++) {
		int clock = 0;
		for (int j = 0; j < 4; j++) {
			clock = clock * 10 + c[(i + j) % 4];
		}
		if (min > clock) min = clock;
	}
	return min;
}

int main() {
	input();
	int target = getClock(card);
	int tmp[4] = {};

	for (int a = 1; a < 10; a++) {
		for (int b = 1; b < 10; b++) {
			for (int c = 1; c < 10; c++) {
				for (int d = 1; d < 10; d++) {
					tmp[0] = a;
					tmp[1] = b;
					tmp[2] = c;
					tmp[3] = d;

					res.push_back(getClock(tmp));
				}
			}
		}
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	int cnt = find(res.begin(), res.end(), target) - res.begin();
	cout << cnt + 1 << "\n";
	return 0;
}