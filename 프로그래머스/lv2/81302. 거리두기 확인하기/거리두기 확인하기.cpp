#include <string>
#include <vector>

using namespace std;

vector<vector<int>> visited;
vector<string> place;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int y, int x, int level){
    visited[y][x] = 1;
    if(level == 2) return;
    
    for(int i = 0; i < 4; i++){
        int dy = y + dr[i];
        int dx = x + dc[i];
        
        if(dy < 0 || dy >= 5) continue;
        if(dx < 0 || dx >= 5) continue;
        if(place[dy][dx] == 'X') continue;
        if(visited[dy][dx]) continue;
        dfs(dy, dx, level + 1);
    }
}

int isOkay(){
    visited = vector<vector<int>> (5, vector<int> (5, 0));
    
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            if(place[y][x] != 'P') continue;
            if(visited[y][x]) return 0;
            dfs(y, x, 0);
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < 5; i++){
        place = places[i];
        answer.push_back(isOkay());
    }
    return answer;
}