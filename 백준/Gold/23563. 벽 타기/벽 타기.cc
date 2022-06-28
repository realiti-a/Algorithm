#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <climits>
using namespace std;

struct pos {
    int y, x;
};

bool operator==(pos a, pos b){ 
    if(a.y != b.y) return false;
    if(a.x != b.x) return false;
    return true;
}

int dr[] = {-1, 1, 0, 0}; 
int dc[] = {0, 0, -1, 1}; 

vector<string> map;
vector<vector<int>> visited;
int H, W;
//S start of map, E end of map;
pos S, E;

void input(){
    cin >> H >> W;
    map = vector<string> (H, "");
    visited = vector<vector<int>> (H, vector<int>(W, INT_MAX));
    for(int y = 0; y < H; y++) cin >> map[y];
}

void findPosition(){
    int cnt = 0;
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            if(map[y][x] == 'S'){
                cnt++;
                S.y = y;
                S.x = x;
            }   
            else if(map[y][x] == 'E'){
                cnt++;
                E.y = y;
                E.x = x;
            }   
            if(cnt == 2) return;
        }   
    }   
}

bool isAdjacent(int y, int x){ 
    for(int i = 0; i < 4; i++){
        int dy = y + dr[i];
        int dx = x + dc[i];
    
        if(map[dy][dx] == '#') return true;
    }   
    return false;
}

void solve(){
    deque<pos> dq;
    dq.push_back(S);
    visited[S.y][S.x] = 0;

    while(!dq.empty()){
        pos now = dq.front();
        dq.pop_front();

        if(now == E) {
            cout << visited[E.y][E.x] << "\n";
            return;
        }

        for(int i = 0; i < 4; i++){
            int dy = now.y + dr[i];
            int dx = now.x + dc[i];

            if(map[dy][dx] == '#') continue;

            bool nowAdjacent = isAdjacent(now.y, now.x);

            if(isAdjacent(dy, dx) && nowAdjacent){
                if(visited[dy][dx] <= visited[now.y][now.x]) continue;
                visited[dy][dx] = visited[now.y][now.x];
                dq.push_front({dy, dx});
            }
            else {
                if(visited[dy][dx] <= visited[now.y][now.x] + 1) continue;
                visited[dy][dx] = visited[now.y][now.x] + 1;
                dq.push_back({dy, dx});
            }
        }
    }
}

int main(){
    input();
    findPosition();
    solve();
    return 0;
}
