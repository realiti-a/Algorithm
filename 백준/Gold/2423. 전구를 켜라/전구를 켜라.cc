#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <climits>

using namespace std;

struct pos {
    int y, x;
};
//map에서 탐색
int dr[] = {-1, -1, 0, 0};
int dc[] = {-1, 0, -1, 0};
//visited 탐색
int tr[] = {-1, -1, 1, 1};
int tc[] = {-1, 1, -1, 1};
//비교군
char line[] = {0x5C, 0x2F, 0x2F, 0x5C};

vector<string> map;
vector<vector<int>> visited;

int N, M;

void input(){
    cin >> N >> M;
    map = vector<string>(N, "");
    visited = vector<vector<int>> (N + 1, vector<int>(M + 1, INT_MAX));
    for(int y = 0; y < N; y++) cin >> map[y];
}

void solve(){
    deque<pos> dq;
    dq.push_back({0, 0});
    visited[0][0] = 0;

    while(!dq.empty()){
        pos now = dq.front();
        dq.pop_front();

        if(now.y == N && now.x == M) {
            cout << visited[now.y][now.x] << "\n";
            return;
        }

        for(int i = 0; i < 4; i++){
            int dy = now.y + dr[i];
            int dx = now.x + dc[i];

            if(dy < 0 || dy >= N) continue;
            if(dx < 0 || dx >= M) continue;

            int ty = now.y + tr[i];
            int tx = now.x + tc[i];

            if(ty < 0 || ty > N) continue;
            if(tx < 0 || tx > M) continue;

            if(map[dy][dx] != line[i]){
                if(visited[ty][tx] <= visited[now.y][now.x] + 1) continue;
                visited[ty][tx] = visited[now.y][now.x] + 1;
                dq.push_back({ty, tx});
            }
            else if(map[dy][dx] == line[i]){
                if(visited[ty][tx] <= visited[now.y][now.x]) continue;
                visited[ty][tx] = visited[now.y][now.x];
                dq.push_front({ty, tx});
            }
        }
    }
    cout << "NO SOLUTION\n";
    return;
}

int main(){
    input();
    solve();
    return 0;
}
