#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int N, M;

void input() {
	cin >> N >> M;
	cnt = 0;
}

vector<vector<long long>> comb;

long long combination() {
	comb = vector<vector<long long>>(M + 1, vector<long long>(M + 1, 0));
	for (int y = 1; y <= M; y++) {
		for (int x = 0; x <= y; x++) {
			if (x == 0 || x == y) comb[y][x] = 1;
			else {
				comb[y][x] = comb[y - 1][x] + comb[y - 1][x - 1];
			}
		}
	}

	return comb[M][N];
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		cout << combination() << "\n";
	}
	return 0;
}