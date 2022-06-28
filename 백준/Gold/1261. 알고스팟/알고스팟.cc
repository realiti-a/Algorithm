#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <climits>
using namespace std;

struct pos {
    int y, x;
};

int N, M;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0}; 

vector<vector<int>> visited;
vector<string> map;

void input(){
    cin >> M >> N;
    map = vector<string> (N, "");
    visited = vector<vector<int>> (N, vector<int>(M, INT_MAX));

    for(int y = 0; y < N; y++) cin >> map[y];
}

void solve(){
    deque<pos> dq; 
    dq.push_back({0, 0});
    visited[0][0] = 0;

    while(!dq.empty()){
        pos now = dq.front();
        dq.pop_front();

        if(now.y == N - 1 && now.x == M - 1) {
            cout << visited[now.y][now.x] << "\n";
            return;
        }   
        for(int i = 0; i < 4; i++){
            int dy = now.y + dr[i];
            int dx = now.x + dc[i];

            if(dy < 0 || dy >= N) continue;
            if(dx < 0 || dx >= M) continue;

            if(map[dy][dx] == '0'){
                if(visited[dy][dx] <= visited[now.y][now.x]) continue;
                visited[dy][dx] = visited[now.y][now.x];
                dq.push_front({dy, dx});
            }   
            else if(map[dy][dx] == '1'){
                if(visited[dy][dx] <= visited[now.y][now.x] + 1) continue;
                visited[dy][dx] = visited[now.y][now.x] + 1;
                dq.push_back({dy, dx});
            }   
        }   
    }   
}

int main(){
    input();
    solve();
    return 0;
}