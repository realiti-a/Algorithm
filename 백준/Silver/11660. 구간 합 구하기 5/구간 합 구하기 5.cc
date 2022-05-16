#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	board = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> board[y][x];

			board[y][x] += board[y - 1][x] + board[y][x - 1] - board[y - 1][x - 1];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		int result = board[x2][y2] - (board[x1 - 1][y2] + board[x2][y1 - 1] - board[x1 - 1][y1 - 1]);
		cout << result << "\n";
	}
	return 0;
}