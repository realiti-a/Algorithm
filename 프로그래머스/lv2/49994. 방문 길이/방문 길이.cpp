#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    vector<vector<int>> udMap = vector<vector<int>> (10, vector<int>(11, 0)); //가로값이 x축 좌표, 세로 값이 up, down 표시
    vector<vector<int>> lrMap = vector<vector<int>> (11, vector<int>(10, 0)); //세로값이 y축 좌표, 가로 값이 left, right 표시
    
    int y = 5, x = 5;
    
    for(int i = 0; i < dirs.length(); i++){
        if(dirs[i] == 'U'){
            if(y + 1 > 10) continue;
            udMap[y][x] = 1;
            y++;
        }
        else if(dirs[i] == 'D'){
            if(y - 1 < 0) continue;
            udMap[y - 1][x] = 1;
            y--;
        }
        else if(dirs[i] == 'L'){
            if(x - 1 < 0) continue;
            lrMap[y][x - 1] = 1;
            x--;
        }
        else if(dirs[i] == 'R'){
            if(x + 1 > 10) continue;
            lrMap[y][x] = 1;
            x++;
        }
    }
    
    for(int y = 0; y < udMap.size(); y++){
        for(int x = 0; x < udMap[y].size(); x++){
            if(udMap[y][x]) answer++;
        }
    }
    
    for(int y = 0; y < lrMap.size(); y++){
        for(int x = 0; x < lrMap[y].size(); x++){
            if(lrMap[y][x]) answer++;
        }
    }
    
    return answer;
}