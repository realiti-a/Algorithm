#include <iostream>
#include <queue>
using namespace std;

int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1}; 
int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};

struct pos {
    int y, x;
};

int I;
vector< vector<int> > visited;

pos start, final;
void input(){
    cin >> I;
    
    visited = vector< vector<int> > (I, vector<int>(I, 0));

    cin >> start.y >> start.x;
    cin >> final.y >> final.x;
}

void bfs(){
    queue<pos> q;
    q.push(start);
    visited[start.y][start.x] = 1;
    
    while(!q.empty()){
        pos now = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int dy = now.y + dr[i];
            int dx = now.x + dc[i];

            if(dy < 0 || dy >= I) continue;
            if(dx < 0 || dx >= I) continue;

            if(visited[dy][dx]) continue;

            visited[dy][dx] = visited[now.y][now.x] + 1;
            q.push({dy, dx});

            if(dy == final.y && dx == final.x) break;
        }   
    }   
}


int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        input();
        bfs();
        cout << visited[final.y][final.x] - 1 << "\n";
    }   
    return 0;
}