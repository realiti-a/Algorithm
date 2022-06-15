#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int maxDay = 0;
    for(int i = 0; i < progresses.size(); i++){
        int remain = 100 - progresses[i];
        
        int day = remain / speeds[i];
        if(remain % speeds[i]) day++;
        
        if(day > maxDay){
            maxDay = day;
            answer.push_back(1);
        }
        else {
            answer[answer.size() - 1]++;
        }
    }
    return answer;
}