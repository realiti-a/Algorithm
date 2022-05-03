#include <iostream>
#include <vector>
using namespace std;

#define INF 21e8

vector<vector<int>> map;
vector<int> visited;
vector<int> dist;

//아직 방문하지 않은 정점 중 가장 거리가 짧은 곳의 index 반환
int getSmallIndex(){
    int min = INF;
    int index = 0;
    
    for(int i = 0; i < dist.size(); i++){
        if(visited[i]) continue;
        if(dist[i] < min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start){
    //start에서부터의 거리 표시
    for(int i = 0; i < dist.size(); i++){
        dist[i] = map[start][i];
    }
    //start 방문한 것으로 표시
    visited[start] = 1;
    
    for(int i = 0; i < dist.size(); i++){
        int now = getSmallIndex();
        //방문하지 않은 점들 중 거리가 제일 짧은 점 찾아서 방문
        visited[now] = 1;
        
        //거리가 제일 짧은 점에서 다른 점들로 향함 대신에 방문했던 점은 빼고
        for(int to = 0; to < dist.size(); to++){
            if(visited[to]) continue;
            if(dist[to] > dist[now] + map[now][to]){
                dist[to] = dist[now] + map[now][to];
            }
        }
    }
}

int solution(int N, vector<vector<int> > roads, int K) {
    int answer = 0;
    
    //초기화 작업
    visited = vector<int> (N, 0);
    dist = vector<int>(N, INF);
    
    map = vector<vector<int>>(N, vector<int>(N, INF));
    
    for(auto road: roads){
        int a = road[0] - 1, b = road[1] - 1;
        int weight = road[2];
        
        if(map[a][b] < weight) continue;
        
        map[a][b] = weight;
        map[b][a] = weight;
    }
    for(int i = 0; i < N; i++) map[i][i] = 0;
    
    //dijkstra
    dijkstra(0);
    
    //거리가 K이하인 점들 찾기
    for(auto d : dist) {
        cout << d << " ";
        if(d <= K) answer++;
    }
    return answer;
}