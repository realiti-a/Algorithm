#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct work{
	int day;
	int pay;
};

work works[15] = {};
int N;

void input() {
	cin >> N;
	int day, pay;
	for (int i = 1; i <= N; i++) {
		cin >> day >> pay;
		works[i] = { day, pay };
	}
}

int findMax(vector<int> pay) {
	int max = 0;
	for (int i = 0; i < pay.size(); i++) {
		if (pay[i] > max) max = pay[i];
	}
	return max;
}
int maxPay(int n) {
	int lastDay = n;
	vector<int> pay;
	for (int i = 1; i <= N; i++) {
		if (i + works[i].day > lastDay) continue;
		pay.push_back(works[i].pay + maxPay(i));
	}
	return findMax(pay);
}

int main() {
	input();
	cout << maxPay(N + 1);

	return 0;
}