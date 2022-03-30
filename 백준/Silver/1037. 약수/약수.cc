#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> factor;
void input() {
	cin >> N;
	factor.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> factor[i];
	}
}

int getN() {
	sort(factor.begin(), factor.end());
	return factor[0] * factor[factor.size() - 1];
}

int main() {
	input();
	cout << getN() << "\n";
	return 0;
}