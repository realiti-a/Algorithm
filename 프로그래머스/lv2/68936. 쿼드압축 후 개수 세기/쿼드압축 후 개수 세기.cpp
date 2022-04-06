#include <string>
#include <vector>

using namespace std;

vector<int> result;
vector<vector<int>> map;

void press(int dy, int dx, int size){
    int flag = 0;
    int ans = map[dy][dx];
    for(int y = dy; y < dy + size; y++){
        for(int x = dx; x < dx + size; x++){
            if(map[y][x] != ans) {
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    
    if(!flag) result.push_back(ans);
    else {
        press(dy, dx, size/2);
        press(dy + size/2, dx, size/2);
        press(dy, dx + size/2, size/2);
        press(dy + size/2, dx + size/2, size/2);
    }
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    map = arr;
    
    press(0, 0, arr.size());
    
    for(int i = 0; i < result.size(); i++){
        if(result[i]) answer[1]++;
        else answer[0]++;
    }
    return answer;
}