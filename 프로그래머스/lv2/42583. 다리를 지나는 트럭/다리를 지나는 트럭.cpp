#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total_weight = 0;
    queue<int> bridge;
    
    for(int i = 0; i < bridge_length; i++) bridge.push(0);
    
    for(int i = 0; i < truck_weights.size(); i++){
        int next = truck_weights[i];
        
        while(true){
            answer++;
            total_weight -= bridge.front();
            bridge.pop();
            
            if(total_weight + next <= weight) break;
            bridge.push(0);
        }
        
        bridge.push(next);
        total_weight += next;
    }
    
    while(!bridge.empty()) {
        answer++;
        bridge.pop();
    }
    
    return answer;
}