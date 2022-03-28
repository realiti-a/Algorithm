#include <iostream>
using namespace std;

int N, M, MAX = 0;
int trees[1000000];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		if (trees[i] > MAX) MAX = trees[i];
	}
}

long long getHeight(int height) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (trees[i] > height) {
			sum += trees[i] - height;
		}
	}
	return sum;
}

int binSearch() {
	int start = 0, end = MAX;
	int ret = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		long long sum = getHeight(mid);
		if (sum < M) {
			end = mid - 1;
		}
		else {
			ret = mid;
			start = mid + 1;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << binSearch() << "\n";
	return 0;
}