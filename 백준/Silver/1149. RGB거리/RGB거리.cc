#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> houses;
void input() {
	cin >> N;

	houses = vector<vector<int>>(N, vector<int>(3, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> houses[i][j];
		}
	}
}

void paint() {
	for (int y = 1; y < N; y++) {
		for (int x = 0; x < 3; x++) {
			int min = 21e8;
			for (int k = 0; k < 3; k++) {
				if (k == x) continue;
				if (houses[y - 1][k] < min) min = houses[y - 1][k];
			}
			houses[y][x] += min;
		}
	}
}

int main() {
	input();
	paint();

	int min = 21e8;
	for (int i = 0; i < 3; i++) {
		if (houses[N - 1][i] < min) min = houses[N - 1][i];
	}
	cout << min << "\n";
	return 0;
}