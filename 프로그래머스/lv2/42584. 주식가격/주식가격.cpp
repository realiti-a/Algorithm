#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++){
        int lastDay = i;
        for(int j = i + 1; j < prices.size(); j++){
            if(prices[j] < prices[i]){
                lastDay = j;
                break;
            }
        }
        if(lastDay == i && i != prices.size() - 1){
            answer.push_back(prices.size() - i - 1);
        } 
        else answer.push_back(lastDay - i);
    }
    return answer;
}