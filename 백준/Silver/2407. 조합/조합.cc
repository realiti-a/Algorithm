#include <iostream>
#include <string>
using namespace std;

string combi[101][101] = {};

string add(string a, string b) {
	int size = a.size() > b.size() ? a.size() : b.size();

	int sum = 0;
	string result = "";
	for (int i = 1; i <= size; i++) {
		if (i <= a.size()) sum += a[a.size() - i] - '0';
		if (i <= b.size()) sum += b[b.size() - i] - '0';

		result = (char)(sum % 10 + '0') + result;
		sum /= 10;
	}

	if (sum) result = (char)(sum + '0') + result;

	return result;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 0; x <= y; x++) {
			if (x == 0 || x == y) combi[y][x] = "1";
			else combi[y][x] = add(combi[y - 1][x], combi[y - 1][x - 1]);
		}
	}

	cout << combi[N][M] << "\n";
	return 0;
}