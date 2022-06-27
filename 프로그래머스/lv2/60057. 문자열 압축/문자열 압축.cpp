#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int i = 1; i <= s.length(); i++){
        string res = "";
        string pre = "";
        int cnt = 0;
        
        for(int j = 0; j < s.length(); j += i){
            string now = "";
            if(j + i > s.length()) now = s.substr(j);
            else now = s.substr(j, i);
            
            if(now == pre) cnt++;
            else {
                if(cnt == 1) {
                    res += pre;
                }
                else if(cnt){
                    res += to_string(cnt) + pre;
                }
                cnt = 1;
                pre = now;
            }
        }
        
        if(cnt == 1) res += pre;
        else if(cnt) res += to_string(cnt) + pre;
        
        int resLength = res.length();
        if(resLength < answer) answer = resLength;
    }
    return answer;
}