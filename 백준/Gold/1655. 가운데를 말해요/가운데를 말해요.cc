#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, less<int>> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int mid = 0;

	int input;
	cin >> input;

	mid = input;
	cout << mid << "\n";
	
	for (int i = 0; i < N - 1; i++) {
		cin >> input;

		if (mid < input)min_pq.push(input);
		else max_pq.push(input);

		while (min_pq.size() - max_pq.size() != 0 && min_pq.size() - max_pq.size() != 1) {
			//작은 수가 더 많은 경우
			if (max_pq.size() > min_pq.size()) {
				min_pq.push(mid);
				mid = max_pq.top();
				max_pq.pop();
			}
			//큰 수가 더 많은 경우
			else {
				max_pq.push(mid);
				mid = min_pq.top();
				min_pq.pop();
			}
		}

		cout << mid << "\n";
	}

	return 0;
}