#include <iostream>
#include <vector>
#include <deque>
#include <climits>

#define DIE 1000
#define DANGER 1

using namespace std;

struct pos {
    int y, x;
};

int dr[] = {-1, 1, 0, 0}; 
int dc[] = {0, 0, -1, 1}; 

vector<vector<int>> visited;
vector<vector<int>> map;

void fillMap(int x1, int y1, int x2, int y2, int fill){
    int minX = x1 < x2 ? x1 : x2; 
    int maxX = x1 > x2 ? x1 : x2; 
    int minY = y1 < y2 ? y1 : y2; 
    int maxY = y1 > y2 ? y1 : y2; 

    for(int y = minY; y <= maxY; y++){
        for(int x = minX; x <= maxX; x++){
            map[y][x] = fill;
        }   
    }   
}

void input(){
    int N, M;
    int x1, y1, x2, y2; 

    visited = vector<vector<int>> (501, vector<int>(501, INT_MAX));
    map = vector<vector<int>> (501, vector<int>(501, 0));

    //danger area
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x1 >> y1 >> x2 >> y2; 
        fillMap(x1, y1, x2, y2, DANGER);
    }   
    //dying area
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> x1 >> y1 >> x2 >> y2; 
        fillMap(x1, y1, x2, y2, DIE);
    }   
}

void solve(){
    deque<pos> dq; 
    dq.push_back({0, 0});
    visited[0][0] = 0;

    while(!dq.empty()){
        pos now = dq.front();
        dq.pop_front();

        if(now.y == 500 && now.x == 500){
            cout << visited[now.y][now.x] << "\n";
            return;
        }

        for(int i = 0; i < 4; i++){
            int dy = now.y + dr[i];
            int dx = now.x + dc[i];

            if(dy < 0 || dy > 500) continue;
            if(dx < 0 || dx > 500) continue;

            if(map[dy][dx] == DIE) continue;
            else if(map[dy][dx] == DANGER){
                if(visited[dy][dx] <= visited[now.y][now.x] + 1) continue;
                visited[dy][dx] = visited[now.y][now.x] + 1;
                dq.push_back({dy, dx});
            }
            else {
                if(visited[dy][dx] <= visited[now.y][now.x]) continue;
                visited[dy][dx] = visited[now.y][now.x];
                dq.push_front({dy, dx});
            }
        }
    }
    cout << -1 << "\n";
    return;
}

int main(){
    input();
    solve();
    return 0;
}
