#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> st;
int N, M;
void input() {
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		st.insert(str);
	}
}

int printing() {
	string str;
	int result = 0;
	for (int i = 0; i < M; i++) {
		cin >> str;

		if (st.find(str) == st.end()) continue;
		result++;
	}
	return result;
}

int main() {
	input();
	cout << printing() << "\n";

	return 0;
}