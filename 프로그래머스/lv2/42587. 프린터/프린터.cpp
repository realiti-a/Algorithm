#include <string>
#include <vector>
#include <queue>
using namespace std;
struct document {
    int order;
    int importance;
};

int importances[10] = {};
queue<document> q;

int getNextMax(){
    for(int i = 9; i >= 0;i--){
        if(importances[i]) return i;
    }
    return 0;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
        importances[priorities[i]]++;
    }
    int maxImportance = getNextMax();
    
    while(!q.empty()){
        document now = q.front();
        q.pop();
        
        if(now.importance == maxImportance){
            importances[maxImportance]--;
            maxImportance = getNextMax();
            answer++;
            if(now.order == location) break;
        }
        else {
            q.push(now);
        }
    }
    
    return answer;
}