#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> incLength;
vector<int> descLength;
int N;

int main() {
	cin >> N;
	arr = vector<int>(N, 0); incLength = arr; descLength = arr;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		incLength[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && incLength[j] >= incLength[i]) {
				incLength[i] = incLength[j] + 1;
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		descLength[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[i] && descLength[j] >= descLength[i]) {
				descLength[i] = descLength[j] + 1;
			}
		}
	}

	int maxLength = 0;
	for (int i = 0; i < N; i++) {
		int nowLength = incLength[i] + descLength[i];
		if (nowLength > maxLength) maxLength = nowLength;
	}

	cout << maxLength - 1 << "\n";
	return 0;
}