#include <iostream>
using namespace std;

int queens[15];
int N, cnt, flag;

void input() {
	cin >> N;
	cnt = 0;
}

void pickQueens(int level) {
	if (level == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		flag = 0;
		for (int j = 0; j < level; j++) {
			if (queens[j] == i) flag = 1;
			else if (abs(queens[j] - i) == abs(level - j)) flag = 1;
			if (flag) break;
		}
		if (!flag) {
			queens[level] = i;
			pickQueens(level + 1);
			queens[level] = 0;
		}
	}
}

int main() {
	input();
	pickQueens(0);
	cout << cnt << "\n";
	return 0;
}