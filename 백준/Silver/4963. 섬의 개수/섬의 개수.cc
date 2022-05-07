#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > map;
vector< vector<int> > visited;
int w, h;
void input(){
    cin >> w >> h;

    if(w == 0 && h == 0) exit(0);
    map = vector< vector<int> > (h, vector<int>(w, 0));
    visited = map;
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            cin >> map[y][x] ;
        }   
    }   
}

int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1}; 
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1}; 

void dfs(int y, int x){ 
    for(int i = 0; i < 8; i++){
        int dy = y + dr[i];
        int dx = x + dc[i];

        if(dy < 0 || dy >= h) continue;
        if(dx < 0 || dx >= w) continue;

        if(visited[dy][dx]) continue;
        if(!map[dy][dx]) continue;
    
        visited[dy][dx] = 1;
        dfs(dy, dx);
    }   
}

int dfsAll(){
    int cnt = 0;
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            if(visited[y][x]) continue;
            if(!map[y][x]) continue;

            cnt++;
            visited[y][x] = 1;
            dfs(y, x); 
        }   
    }   
    return cnt;
}

int main(){
    while(1){
        input();
        cout << dfsAll() << "\n";
    }   
    return 0;
}