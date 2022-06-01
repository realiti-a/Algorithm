#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m;

void makeCourse(int level, int totalLevel, string order, string madeCourse = "", int start = 0){
    if(level == totalLevel){
        if(m.find(madeCourse) != m.end()){
            m[madeCourse]++;
            return;
        }
        else {
            m[madeCourse] = 1;
            return;
        }
    }
    
    for(int i = start; i < order.length(); i++){
        makeCourse(level + 1, totalLevel, order, madeCourse + order[i], i + 1);
    }
}

void haveSameCourse(string a, string b){
    if(a.length() < b.length()){
        for(int i = 0; i < a.length(); i++){
            int flag = 0;
            for(int j = 0; j < b.length(); j++){
                if(a[i] == b[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return;
        }
        
        //flag 1이면 a의 코스가 b에 있었다는 뜻
        //a와 b가 동일한 코스다
        //개수마저 같으면 더 짧은 a 삭제
        if(m[a] == m[b]) m.erase(a);
    }
    else {
        for(int i = 0; i < b.length(); i++){
            int flag = 0;
            for(int j = 0; j < a.length(); j++){
                if(b[i] == a[j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return;
        }
        
        if(m[a] == m[b]) m.erase(b);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for(auto order : orders){
        sort(order.begin(), order.end());
        for(auto courseLength : course){
            if(order.length() < courseLength) continue;
            
            makeCourse(0, courseLength, order);
        }
    }
    
    // 같은 코스 포함하고 있으면, 개수 비교 동일하면 삭제
    
    vector<string> answer;
    
    // 각 코스 길이 별 최대값
    for(auto c : course){
        int maxValue = 0;
        for(auto e : m){
            if(e.first.length() == c && e.second > maxValue){
                maxValue = e.second;
            }
        }
        //그 길이 가진 애들 answer 배열에 담기
        if (maxValue < 2) continue;
        for(auto e : m){
            if(e.first.length() == c && e.second == maxValue){
                answer.push_back(e.first);
            }
        }
    }
    
    for(auto e : m) cout << e.first << " " << e.second << "\n";
    
    sort(answer.begin(), answer.end());
    return answer;
}