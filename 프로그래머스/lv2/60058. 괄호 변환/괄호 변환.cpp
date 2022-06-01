#include <string>
#include <vector>
#include <stack>
using namespace std;

int isOkay(string str){
    int cnt = 0;
    for(auto c : str){
        if(c == '(') cnt++;
        else cnt--;
        
        if(cnt < 0) return 0;
    }
    if(cnt == 0) return 1;
    return 0;
}

string makeBalance(string s){
    // 1.
    if(s == "") return s;
    // 2.
    int cnt = 0;
    string u, v;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;
        
        if(cnt == 0) {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1);
            break;
        }
    }
    
    // 3.
    if(isOkay(u)){
        return u + makeBalance(v);
    }
    // 4.
        //4 - 1, 2, 3.
    string res =  "(" + makeBalance(v) + ")";
        
    for(int i = 1; i < u.length() - 1; i++){
        if(u[i] == '(') res += ')';
        else res += '(';
    }
    
    return res;
}

string solution(string p) {
    string answer = makeBalance(p);
    return answer;
}