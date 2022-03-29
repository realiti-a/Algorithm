#include <iostream>
#include <vector>

using namespace std;

int N, M, B;
vector<int> map(257);

void input() {
	cin >> N >> M >> B;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int land;
			cin >> land;
			map[land]++;
		}
	}
}

int getTime(int height) {
	int inventory = B;
	int time = 0;
	for (int i = 256; i >= 0; i--) {
		if (i < height) {
			int cnt = (height - i) * map[i];
			if (inventory < cnt) return -1;
			inventory -= cnt;
			time += cnt;
		}
		else if (i > height) {
			int cnt = (i - height) * map[i];
			inventory += cnt;
			time += cnt * 2;
		}
	}

	return time;
}

int main(){
	input();
	int min = 123456789, height;

	for (int i = 0; i <= 256; i++) {
		int time = getTime(i);
		if (time == -1) continue;

		if (time <= min) {
			min = time;
			height = i;
		}
	}

	cout << min << " " << height << "\n";
	return 0;
}