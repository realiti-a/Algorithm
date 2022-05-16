#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
vector<vector<int>> accSum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	
	accSum = vector<vector<int>>(26, vector<int>(str.length() + 1, 0));

	for (int x = 0; x < str.length(); x++) accSum[str[x] - 'a'][x + 1]++;

	for (int x = 1; x <= str.length(); x++) {
		for (int y = 0; y < 26; y++) {
			accSum[y][x] += accSum[y][x - 1];
		}
	}
	
	int N;
	cin >> N;

	char tar;
	int start, last;
	for (int i = 0; i < N; i++) {
		cin >> tar >> start >> last;
		cout << accSum[tar - 'a'][last + 1] - accSum[tar - 'a'][start] << "\n";
	}
	return 0;
}