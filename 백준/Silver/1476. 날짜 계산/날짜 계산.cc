#include <iostream>
using namespace std;

int E, S, M;
void input() {
	cin >> E >> S >> M;
}

int getYear() {
	for (int i = 0; i <= 7980; i++) {
		if (i % 15 == E - 1 && i % 28 == S - 1 && i % 19 == M - 1) return i + 1;
	}
	return -1;
}

int main() {
	input();
	cout << getYear() << "\n";
	return 0;
}