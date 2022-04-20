#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> used;
    
    string pre = words[0], cur = "";
    used.insert(pre);
    int setSize = used.size();
    
    int breakNumber = 0;
    
    for(int i = 1; i < words.size(); i++){
        cur = words[i];
        
        used.insert(cur);
        if(setSize == used.size()) {
            breakNumber = i;
            break;
        }
        else if(pre[pre.length() - 1] != cur[0]){
            breakNumber = i;
            break;
        }
        else if(cur.length() == 1) {
            breakNumber = i;
            break;
        }
        pre = cur;
        setSize = used.size();
    }
    
    cout << breakNumber << "\n";
    
    if(!breakNumber) return {0, 0};
    answer.push_back(breakNumber % n + 1);
    answer.push_back(breakNumber / n + 1);
    return answer;
}