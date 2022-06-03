#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> numbers;
vector<int> path(6, 0);
void input() {
	cin >> N;
	if (N == 0) exit(0);
	numbers = vector<int>(N, 0);
	for (int i = 0; i < N; i++) cin >> numbers[i];
}

void chooseNumber(int level, int start) {
	if (level == 6) {
		for (int i = 0; i < 6; i++) cout << path[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i < N; i++) {
		path[level] = numbers[i];
		chooseNumber(level + 1, i + 1);
		path[level] = 0;
	}
}

int main() {
	while (true) {
		input();
		chooseNumber(0, 0);
		cout << "\n";
	}
	return 0;
}