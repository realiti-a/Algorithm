#include <iostream>
#include <vector>
using namespace std;

int N;
int numbers[4000001] = {};
vector<int> primes;

void  makePrime() {
	for (int i = 2; i <= N; i++) {
		if (numbers[i]) continue;
		primes.push_back(i);
		for (int j = 2; j * i <= N; j++) numbers[j * i] = 1;
	}
}

int getRes() {
	int start = 0, end = 0, sum = 0;
	int cnt = 0;
	while (true) {
		//아직 N보다 sum 값이 작고, 아직 더할 값이 남아 있다면 end 포인터를 뒤로 옮기고 값 추가
		if (sum < N && end < primes.size()) sum += primes[end++];
		//N보다 sum 값이 크다면, start 포인터를 뒤로 옮기고 값 삭제
		else if (sum > N) sum -= primes[start++];
		
		//sum 이 N과 같아졌다면 cnt 하나 빼고, start 포인터 뒤로 옮기고 값 삭제
		if (sum == N) {
			cnt++;
			sum -= primes[start++];
		}
		//만약 sum이 N보다 작고, end 포인터도 끝에 다다랐다면, 종료.
		if (sum < N && end == primes.size()) break;
	}
	return cnt;
}

int main() {
	cin >> N;
	makePrime();
	cout << getRes() << "\n";
	return 0;
}