#include <iostream>
using namespace std;

int N;
int triangle[500][500] = {};

void input() {
	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x <= y; x++) {
			cin >> triangle[y][x];
		}
	}
}

void dp() {
	//현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
	for (int y = 1; y < N; y++) {
		for (int x = 0; x <= y; x++) {
			int left = x - 1;
			int right = x;
	
			int leftValue = 0, rightValue = 0;
			if (left >= 0) leftValue = triangle[y - 1][left];
			if (right <= y) rightValue = triangle[y - 1][right];

			int maxValue = leftValue > rightValue ? leftValue : rightValue;

			triangle[y][x] += maxValue;
		}
	}
}


int main() {
	input();

	dp();

	int maxValue = 0;
	for (int x = 0; x < N; x++) {
		if (triangle[N - 1][x] > maxValue) maxValue = triangle[N - 1][x];
	}

	cout << maxValue << "\n";
	return 0;
}