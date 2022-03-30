#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, C;
vector<char> Case;
vector<char> path;
vector<int> visited;
char vowel[] = { 'a', 'e', 'i', 'o', 'u' };

bool isVowel(char c) {
	for (int i = 0; i < 5; i++) {
		if (c == vowel[i]) return true;
	}
	return false;
}

bool isOkay() {
	int vowelCount = 0, elseCount = 0;
	for (int i = 0; i < N; i++) {
		if (isVowel(path[i])) vowelCount++;
		else elseCount++;
	}
	if (vowelCount >= 1 && elseCount >= 2) return true;
	else return false;
}

void print() {
	for (int i = 0; i < N; i++) {
		cout << path[i];
	}
	cout << "\n";
}

void input() {
	cin >> N >> C;
	
	Case.resize(C);
	visited.resize(C, 0);
	path.resize(N);

	for (int i = 0; i < C; i++) {
		cin >> Case[i];
	}

	sort(Case.begin(), Case.end());
}

void makePW(int level, int now) {
	if (level == N) {
		if (isOkay()) {
			print();
		}
		return;
	}
	for (int i = now; i < C; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		path[level] = Case[i];
		makePW(level + 1, i);
		path[level] = 0;
		visited[i] = 0;
	}
}

int main() {
	input();
	
	makePW(0, 0);

	return 0;
}