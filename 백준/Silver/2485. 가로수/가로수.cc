#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> trees;

int getGCD(int a, int b) {
	if (b == 0) return a;

	int remain = a % b;
	return getGCD(b, remain);
}

void input() {
	cin >> N;
	trees = vector<int>(N, 0);
	for (int i = 0; i < N; i++) cin >> trees[i];
	sort(trees.begin(), trees.end());
}

int getRes() {
	int gcd = trees[1] - trees[0];
	for (int i = 1; i < N; i++) {
		int interval = trees[i] - trees[i - 1];
		gcd = getGCD(interval, gcd);
	}

	int totalInterval = trees[N - 1] - trees[0];
	int totalTree = (totalInterval / gcd) + 1;
	return totalTree - N;
}

int main() {
	input();
	cout << getRes() << "\n";
	return 0;
}