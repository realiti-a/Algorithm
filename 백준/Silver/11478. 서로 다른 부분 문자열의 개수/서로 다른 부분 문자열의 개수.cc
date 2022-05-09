#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<string> st;
vector<int> visited;

string str;
void input() {
	cin >> str;
	visited = vector<int>(str.length(), 0);
}

void combination() {
	for (int i = 1; i <= str.length(); i++) {
		//i == substr의 길이
		for (int j = 0; j + i <= str.length(); j++) {
			//j == 시작 위치
			st.insert(str.substr(j, i));
		}
	}
}

int main() {
	input();
	combination();
	cout << st.size() << "\n";
	return 0;
}