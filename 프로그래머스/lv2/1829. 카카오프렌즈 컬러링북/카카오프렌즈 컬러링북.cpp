#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int getArea(int y, int x, int color){
    int area = 1;
    for(int i = 0; i < 4; i++){
        int dy = y + dr[i];
        int dx = x + dc[i];
        
        if(dy < 0 || dy >= map.size()) continue;
        if(dx < 0 || dx >= map[0].size()) continue;
        
        if(visited[dy][dx]) continue;
        if(map[dy][dx] != color) continue;
        
        visited[dy][dx] = 1;
        area += getArea(dy, dx, color);
    }
    return area;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    map = picture;
    visited = vector<vector<int>> (m, vector<int>(n, 0));
    
    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            if(!picture[y][x]) continue;
            if(visited[y][x]) continue;
            
            number_of_area++;
            
            visited[y][x] = 1;
            int area = getArea(y, x, picture[y][x]);
            if(area > max_size_of_one_area) max_size_of_one_area = area;
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}