#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<vector<int>> image;
void input() {
	cin >> N;
	image = vector<vector<int>>(N, vector<int>(N, 0));

	string str;
	for (int y = 0; y < N; y++) {
		cin >> str;
		for (int x = 0; x < N; x++) {
			image[y][x] = str[x] - '0';
		}
	}
}

int isSame(int dy, int dx, int size) {
	int num = image[dy][dx];
	for (int y = dy; y < dy + size; y++) {
		for (int x = dx; x < dx + size; x++) {
			if (image[y][x] != num) return 0;
		}
	}
	return 1;
}

void quadTree(int dy, int dx, int size) {
	if (isSame(dy, dx, size)) {
		cout << image[dy][dx];
		return;
	}
	cout << "(";

	int nextSize = size / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			quadTree(dy + i * nextSize, dx + j * nextSize, nextSize);
		}
	}

	cout << ")";
}

int main() {
	input();
	quadTree(0, 0, N);
	return 0;
}