#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct position {
    int y;
    int x;
};

vector<vector<int>> tomatoes;
vector<vector<int>> visited;
queue<position> ripeTomatoes;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N, M;
void input(){
    cin >> M >> N;
    tomatoes = vector<vector<int>> (N, vector<int>(M, 0));
    visited = vector<vector<int>> (N, vector<int>(M, 0));
    
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            cin >> tomatoes[y][x];
            if(tomatoes[y][x] == 1){
                ripeTomatoes.push({y, x});
            }
        }
    }
}

void ripe(){
    while(!ripeTomatoes.empty()){
        position now = ripeTomatoes.front();
        ripeTomatoes.pop();
        
        for(int i = 0; i < 4; i++){
            int dy = now.y + dr[i];
            int dx = now.x + dc[i];
            
            if(dy < 0 || dy >= N || dx < 0 || dx >= M) continue;
            if(visited[dy][dx]) continue;
            if(tomatoes[dy][dx]) continue;
            
            visited[dy][dx] = visited[now.y][now.x] + 1;
            tomatoes[dy][dx] = 1;
            ripeTomatoes.push({dy, dx});
        }
    }
}

int getRes(){
    int minDay = 0;
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            if(tomatoes[y][x] == -1) continue;
            if(tomatoes[y][x] == 0) return -1;
            if(visited[y][x] > minDay) minDay = visited[y][x];
        }
    }
    return minDay;
}

int main(){
    input();
    ripe();
    cout << getRes() << "\n";
    return 0;
}
