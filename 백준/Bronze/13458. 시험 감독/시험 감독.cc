#include <iostream>
using namespace std;

int N, B, C;
int A[1000001] = {};
int people;
long long totalCount;
void input() {
	totalCount = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> people;
		A[people]++;
	}

	cin >> B >> C;
}

int getCount(int i) {
	int count = 0;

	i -= B;
	count++;

	if (i > 0) {
		count += i / C;
		i %= C;
	}

	if (i > 0) count++;

	return count;
}

void supervisor() {
	for (int i = 1; i <= 1000000; i++) {
		if (!A[i]) continue;
		totalCount += (long long)getCount(i) * A[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	supervisor();
	cout << totalCount;
	return 0;
}