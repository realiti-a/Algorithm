#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<int> visited;
int N, minCost;

void input(){
    cin >> N;
    minCost = INT_MAX;
    map = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<int>(N, 0); 
    for(int y = 0; y < N; y++)
        for(int x = 0;x < N; x++)
            cin >> map[y][x];
}

void traveling(int level, int now, int cost){
    if (cost >= minCost) return;
    if (level == N){ 
        if(!map[now][0]) return;
        int nowCost = cost + map[now][0];
        if(nowCost < minCost) minCost = nowCost;
        return;
    }   
    for(int to = 0; to < N; to++){
        if(visited[to]) continue;
        if(!map[now][to]) continue;
        visited[to] = 1;
        traveling(level + 1, to, cost + map[now][to]);
        visited[to] = 0;
    }   
}

int main(){
    input();
    visited[0] = 1;
    traveling(1, 0, 0); 
    cout << minCost << "\n";
    return 0;
}