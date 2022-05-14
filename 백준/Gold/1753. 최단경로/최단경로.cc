#include <iostream>
#include <queue>
#define INF 21e8
using namespace std;

vector< vector < vector<int> > > edges;
vector<int> dist;

int V, E;
int start;

void input(){
    cin >> V >> E;
    cin >> start;

    edges = vector< vector< vector<int> > >(V + 1);
    dist = vector<int>(V + 1, INF);

    int from, to, weight;
    for(int i = 0; i < E; i++){
        cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
    }
}

void dijkstra(int src){
    priority_queue<pair<int, int>> pq;
    //시작점 queue에 담기
    dist[src] = 0;
    //자기 자신까지의 간선
    pq.push(make_pair(0, src));

    while(!pq.empty()){
        //priority queue는 특성상 가장 큰 값이 front에 온다.
        //그럼 가장 작은 간선이 앞에 오게 하려면?
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();


        if(dist[here] < cost) continue;

        for(int i = 0; i < edges[here].size(); i++){
            int next = edges[here][i][0];
            int nextDist = cost + edges[here][i][1];

            if(dist[next] < nextDist) continue;

            dist[next] = nextDist;
            pq.push(make_pair(-nextDist, next));
        }
    }
}

int main(){
    input();
    dijkstra(start);

    for(int i = 1; i <= V; i++){
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}