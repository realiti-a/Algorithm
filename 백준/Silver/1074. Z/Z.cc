#include <iostream>
using namespace std;

int N, r, c;
void input() {
	cin >> N >> r >> c;
}

int Z(int y, int x, int size, int start) {
	if (size == 1) return start;

	//몇 사분면으로 가야하는지
	int nextSize = size / 2;

	int qy = ((r - y) / nextSize);//얘가 1이거나 0이 나와야 하는데, *2를 하면 제 1, 3 사분면인지, 제 2, 4 사분면인지 알 수 있다.
	int qx = ((c - x) / nextSize);

	//다음 시작 주소
	int dy = qy * nextSize + y;
	int dx = qx * nextSize + x;

	int nextStart = (qy * 2 + qx) * nextSize * nextSize + start;
	return Z(dy, dx, nextSize, nextStart);
}

int pow(int n) {
	int res = 1;
	for (int i = 0; i < n; i++) res *= 2;
	return res;
}

int main() {
	input();

	cout << Z(0, 0, pow(N), 0);
	
	return 0;
}