#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

int N;
int cnt[3] = {};
void input() {
	cin >> N;

	board = vector<vector<int>>(N, vector<int>(N, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) cin >> board[y][x];
	}
}

int isSame(int dy, int dx, int size) {
	int num = board[dy][dx];
	for (int y = dy; y < dy + size; y++) {
		for (int x = dx; x < dx + size; x++) {
			if (board[y][x] != num) return 0;
		}
	}
	return 1;
}

void cutPaper(int dy, int dx, int size) {
	int now = board[dy][dx];
	//모두 같은 걸로 이루어져 있으면, size가 1인 것도 여기서 처리됨
	if (isSame(dy, dx, size)) {
		cnt[now + 1]++;
		return;
	}
	//아니면 9조각으로 분할
	else {
		int nextSize = size / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cutPaper(dy + i * nextSize, dx + j * nextSize, nextSize);
			}
		}
	}
}

int main() {
	input();
	cutPaper(0, 0, N);

	for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";
	return 0;
}