#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> pies;

void input() {
	cin >> N >> K;
	pies = vector<int>(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> pies[i];
	}
}

int main() {
	input();
	
	//100인 파이가 10만개여도 1000만원이라 int 안에 담을 수 있다
	int sum = 0, maxValue = 0;

	//처음 K개의 파이 뇸뇸
	for (int i = 0; i < K; i++) sum += pies[i];
	
	//i + 1부터 시작하는 K개의 파이의 합 구하기(sliding window)
	for (int i = 0; i < N; i++) {
		int removePie = i;
		int addPie = (i + K) % N;

		sum -= pies[removePie];
		sum += pies[addPie];

		if (sum > maxValue) maxValue = sum;
	}

	cout << maxValue << "\n";
	return 0;
}