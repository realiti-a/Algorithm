#include <iostream>
using namespace std;

int W, H, X, Y, P;

int isOkay(int x, int y) {
	//사각형 내부에 있으면 return 1
	if ((x - X) <= W && (x - X) >= 0 && (y - Y) <= H && (y - Y) >= 0) return 1;
	//왼쪽 반원 내에 있으면 return 1
	//왼쪽 반원의 중심으로부터의 거리 제곱 <= radius 제곱
	int radius = H / 2;
	int leftDist = (X - x) * (X - x) + (Y + radius - y) * (Y + radius - y);
	if (leftDist <= radius * radius) return 1;
	//오른쪽 반원 내에 있으면 return 1
	int rightDist = (X + W - x) * (X + W - x) + (Y + radius - y) * (Y + radius - y);
	if (rightDist <= radius * radius) return 1;

	return 0;
}

int main() {
	cin >> W >> H >> X >> Y >> P;

	int x, y;
	int cnt = 0;
	for (int i = 0; i < P; i++) {
		cin >> x >> y;
		cnt += isOkay(x, y);
	}

	cout << cnt << "\n";
	return 0;
}