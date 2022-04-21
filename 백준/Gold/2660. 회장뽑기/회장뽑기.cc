#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> friendList;
vector<int> visited;
int N;

void input() {
	cin >> N;
	friendList = vector<vector<int>>(N + 1);

	int from, to;

	while (true) {
		cin >> from >> to;
		if (from == -1 && to == -1) return;

		friendList[from].push_back(to);
		friendList[to].push_back(from);
	}
}

int bfs(int start) {
	queue<int> q;
	visited = vector<int>(N + 1, 0);
	q.push(start);
	visited[start] = 1;

	int score = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (visited[now] > score) score = visited[now];
		
		for (int i = 0; i < friendList[now].size(); i++) {
			int to = friendList[now][i];

			if (visited[to]) continue;
			visited[to] = visited[now] + 1;
			q.push(to);
		}
	}

	return score - 1;
}

struct people{
	int name;
	int score;
};

int comp(people a, people b) {
	if (a.score == b.score) return a.name < b.name;
	return a.score < b.score;
}
int main() {
	input();
	vector<people> scores;
	for (int i = 1; i <= N; i++) {
		scores.push_back({ i, bfs(i) });
	}

	sort(scores.begin(), scores.end(), comp);
	
	vector<int> chairmans;
	int minScore = scores[0].score;
	
	for (int i = 0; i < scores.size(); i++) {
		if (scores[i].score > minScore) break;
		chairmans.push_back(scores[i].name);
	}

	cout << minScore << " "  << chairmans.size() << "\n";
	for (auto i : chairmans) cout << i << " ";
	cout << "\n";
	return 0;
}