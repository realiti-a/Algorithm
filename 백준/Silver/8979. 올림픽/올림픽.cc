#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct score {
	int nation;
	int gold, silver, bronze;
	int rank;
};
vector<score> scores;

int N, K;
int nation, gold, silver, bronze;

int operator==(score a, score b) {
	if (a.gold != b.gold) return 0;
	if (a.silver != b.silver) return 0;
	if (a.bronze != b.bronze) return 0;
	return 1;
}

int comp(score a, score b) {
	if (a.gold == b.gold && a.silver == b.silver && a.bronze == b.bronze) return a.nation < b.nation;
	if (a.gold == b.gold && a.silver == b.silver) return a.bronze > b.bronze;
	if (a.gold == b.gold) return a.silver > b.silver;
	return a.gold > b.gold;
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> nation >> gold >> silver >> bronze;

		scores.push_back({ nation, gold, silver, bronze , 0});
	}
}

int main() {
	input();
	sort(scores.begin(), scores.end(), comp);
	score comparison = { 0, 0, 0, 0, 0 };
	int rank = 0;

	for (int i = 0; i < scores.size(); i++) {
		if (scores[i] == comparison) scores[i].rank = rank;
		else {
			comparison = scores[i];
			rank = i + 1;
			scores[i].rank = rank;
		}

		if (scores[i].nation == K) break;
	}

	cout << rank << "\n";
	return 0;
}