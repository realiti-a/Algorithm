#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> Buttons(10, 0);

void input() {
	cin >> N;

	int M, breakButton;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> breakButton;

		// Broken buttons set 1
		Buttons[breakButton] = 1;
	}
}

int isOkay(int number) {
	if (number < 0) return 0;
	if (number == 0 && Buttons[0]) return 0;
	while (number) {
		int digit = number % 10;
		if (Buttons[digit]) return 0;
		number /= 10;
	}
	return 1;
}

int getLength(int number) {
	int res = 0;
	if (number == 0) return 1;
	while (number) {
		res++;
		number /= 10;
	}
	return res;
}

int getMin(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	if (c <= a && c <= b) return c;
}

int main() {
	input();

	//현재 채널 100에서 출발해서 +, - 버튼으로만 도달하기
	int plusMinus = abs(N - 100);

	//이 숫자에서부터 출발해서 +, - 버튼으로 가능한 수 찾기
	int upDown = 0, downFlag = 0, upFlag = 0;
	while (true) {
		if (isOkay(N - upDown)) downFlag = 1;
		if (isOkay(N + upDown)) upFlag = 1;
	
		//둘 중 한 군데라도 만족하면 break
		if (downFlag | upFlag) break;

		if (N + upDown > 1000000) break;
		//만족하지 않으면
		upDown++;
	}
	
	int up = 21e8, down = 21e8;
	if (upFlag) up = getLength(N + upDown) + upDown;
	if (downFlag) down = getLength(N - upDown) + upDown;
	
	int result = getMin(up, down, plusMinus);

	cout << result << "\n";

	return 0;
}