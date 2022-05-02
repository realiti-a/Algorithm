#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

vector<vector<int>> map;
vector<vector<int>> visited;

struct pos {
	int y, x;
};

void input() {
	cin >> N >> M;

	map = vector<vector<int>>(N, vector<int>(M, 0));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
}


int getSafety() {
	queue<pos> q;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 2) {
				q.push({ y, x });
			}
		}
	}

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = now.y + dr[i];
			int dx = now.x + dc[i];

			//범위를 벗어나는 곳은 가지 않도록
			if (dy < 0 || dy >= N) continue;
			if (dx < 0 || dx >= M) continue;

			//바이러스거나 벽인 구역은 방문하지 않음.
			if (map[dy][dx]) continue;
			//이미 방문한 구역은 방문하지 않음.
			if (visited[dy][dx]) continue;

			visited[dy][dx] = 1;
			q.push({ dy, dx });
		}
	}

	//바이러스가 퍼지지 않은 곳(값이 0인 곳) count
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!map[y][x] && !visited[y][x]) cnt++;
		}
	}
	return cnt;
}
int main() {
	input();

	int maxValue = -1;

	//랜덤한 위치에 세개의 연구소 자리 선정
	for (int i = 0; i < N * M; i++) {
		//벽이 있는자리나 바이러스가 있는 자리는 피하기 위해서
		if (map[i / M][i % M]) continue;
		//벽을 세워준다
		map[i / M][i % M] = 1;
		for (int j = i + 1; j < N * M; j++) {
			if (map[j / M][j % M]) continue;

			map[j / M][j % M] = 1;
			for (int k = j + 1; k < N * M; k++) {
				if (map[k / M][k % M]) continue;

				map[k / M][k % M] = 1;

				//visited 초기화
				visited = vector<vector<int>>(N, vector<int>(M, 0));
				int safety = getSafety();
				if (safety > maxValue) maxValue = safety;

				map[k / M][k % M] = 0;
			}
			map[j / M][j % M] = 0;
		}
		map[i / M][i % M] = 0;
	}

	cout << maxValue << "\n";
	return 0;
}