#include<vector>
#include<queue>
using namespace std;

struct pos {
    int y, x;
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps){
    int width = maps[0].size();
    int height = maps.size();
    vector<vector<int>> visited(height, vector<int>(width, 0));
    
    queue<pos> q;
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        pos now = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int dy = now.y + dr[i];
            int dx = now.x + dc[i];
            
            if(dy < 0 || dy >= height) continue;
            if(dx < 0 || dx >= width) continue;
            
            if(visited[dy][dx]) continue;
            if(!maps[dy][dx]) continue;
            
            visited[dy][dx] = visited[now.y][now.x] + 1;
            q.push({dy, dx});
        }
    }
    
    if(!visited[height - 1][width - 1]) return -1;
    return visited[height - 1][width - 1];
}