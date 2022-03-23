#include <iostream>
using namespace std;

int lan[10000] = {0, };
int K, N, length, maxLength = 0;

void input() {
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> lan[i];
		if (lan[i] > maxLength) maxLength = lan[i];
	}
}

long long getCount(int length) {
	long long count = 0;
	
	for (int i = 0; i < 10000; i++) {
		count += lan[i] / length;
	}
	return count;
}

int binarySearch() {
	long long start = 1, end = maxLength;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long count = getCount(mid);
		
		if (count < N) end = mid - 1;
		else {
			start = mid + 1;
		}
	}
	return start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	cout << binarySearch() - 1;
	return 0;
}