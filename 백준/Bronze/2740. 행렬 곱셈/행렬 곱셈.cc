#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

vector<vector<int>>product(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> ret(N, vector<int>(K, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				ret[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return ret;
}
int main() {
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) cin >> A[y][x];
	}
	
	cin >> M >> K;
	vector<vector<int>> B(M, vector<int>(K, 0));
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < K; x++) cin >> B[y][x];
	}
	
	vector<vector<int>> ret = product(A, B);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < K; x++) cout << ret[y][x] << " ";
		cout << "\n";
	}
	return 0;
}