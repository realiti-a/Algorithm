#include <string>
#include <vector>

using namespace std;

int checkIncrease(vector<int> pos){
    int flag = 0;
    if(pos[0] == -1) flag = 1;
    
    for(int i = 1; i < pos.size(); i++){
        if(pos[i] == -1) flag = 1;
        if(flag == 1 && pos[i] >= 0) return 0;
        
        if(flag == 0 && pos[i] < pos[i - 1]) return 0;
    }
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    
    for(int i = 0; i < skill_trees.size(); i++){
        vector<int> pos;
        for(int j = 0; j < skill.length(); j++){
            int nPos = skill_trees[i].find(skill[j]);
            pos.push_back(nPos);
        }
        
        if(!checkIncrease(pos)) answer--;
    }
    
    return answer;
}