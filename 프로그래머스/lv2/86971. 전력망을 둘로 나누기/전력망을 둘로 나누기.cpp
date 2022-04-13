#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> visited;

int dfs(int now) {
    visited[now] = 1;
    int component = 1;
    for (int to = 1; to < map[now].size(); to++) {
        if (!map[now][to]) continue;
        if (visited[to]) continue;

        component += dfs(to);
    }
    return component;
}

int dfsAll() {
    vector<int> component;
    for (int i = 1; i < map.size(); i++) {
        if (visited[i]) continue;
        component.push_back(dfs(i));
    }

    return abs(component[1] - component[0]);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 21e8;

    map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

    for (auto wire : wires) {
        map[wire[0]][wire[1]] = 1;
        map[wire[1]][wire[0]] = 1;
    }

    for (auto wire : wires) {
        map[wire[0]][wire[1]] = 0;
        map[wire[1]][wire[0]] = 0;


        visited = vector<int>(n + 1, 0);
        int diff = dfsAll();
        if (diff < answer) answer = diff;

        map[wire[0]][wire[1]] = 1;
        map[wire[1]][wire[0]] = 1;
    }

    return answer;
}
