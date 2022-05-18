#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> tuples;

void split(string s){
    string tmp = "";
    int now = -1;
    for(int i = 1; i < s.length() - 1; i++){
        if(s[i] == '{') {
            tuples.push_back(vector<int>(0));
            now++;
            tmp = "";
        }
        else if(s[i] == '}' || (s[i] == ',' && s[i + 1] != '{')) {
            tuples[now].push_back(stoi(tmp));
            tmp = "";
        }
        else if(s[i] >= '0' && s[i] <= '9') tmp += s[i];
    }
}

int comp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    split(s);
    sort(tuples.begin(), tuples.end(), comp);
    
    vector<int> answer;
    for(int i = 0; i < tuples.size(); i++){
        for(int j = 0; j < tuples[i].size(); j++){
            int flag = 0;
            for(int k = 0; k < answer.size(); k++){
                if(answer[k] == tuples[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            answer.push_back(tuples[i][j]);
        }
    }
    
    return answer;
}
