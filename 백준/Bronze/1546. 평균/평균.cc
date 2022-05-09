#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	
	cin >> N;
	
	int* score = new int[N];

	for (int j = 0; j < N; j++) {
		cin >> score[j];
	}

	sort(score, score + N);

	M = score[N-1];

	int sum=0;
	
	for (int i = 0; i < N; i++) {
		sum += score[i];
	}

	cout << (double) sum * 100 / N / M << "\n";

	delete[] score;

	return 0;
}