#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> I;

vector<vector<int>> product(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> result(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				result[i][j] += (A[i][k] * B[k][j]) % 1000;
				result[i][j] %= 1000;
			}
		}
	}
	return result;
}

vector<vector<int>> exponential(vector<vector<int>> A, long long expo) {
	if (expo == 1) return product(A, I);

	vector<vector<int>> tmp = exponential(A, expo / 2);
	vector<vector<int>> ret = product(tmp, tmp);
	if (expo % 2) ret = product(ret, A);
	return ret;
}

int main() {
	vector<vector<int>> matrix;
	long long B;

	cin >> N >> B;

	I = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) I[i][i] = 1;

	matrix = vector<vector<int>>(N, vector<int>(N, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> matrix[y][x];
		}
	}

	vector<vector<int>> ret = exponential(matrix, B);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << ret[y][x] << " ";
		}
		cout << "\n";
	}
	return 0;
}