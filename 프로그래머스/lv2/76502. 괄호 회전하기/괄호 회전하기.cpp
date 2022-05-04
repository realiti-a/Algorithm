#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++){
        //어디서 시작할지 i
        int cnt = 0;
        stack<char> st;
        
        int flag = 0;
        for(int j = 0; j < s.length(); j++){
            //문자열 한바퀴 회전   
            char now = s[(i + j)%s.length()];
            
            if(now == '(' || now == '[' || now == '{') st.push(now);
            else if(now == ')'){
                if(st.empty()) {
                    flag = 1;
                    break;
                }
                if(st.top() != '('){
                    flag = 1;
                    break;
                }
                else st.pop();
            }
            else if(now == ']'){
                if(st.empty()) {
                    flag = 1;
                    break;
                }
                if(st.top() != '['){
                    flag = 1;
                    break;
                }
                else st.pop();
            }
            else if(now == '}'){
                if(st.empty()) {
                    flag = 1;
                    break;
                }
                if(st.top() != '{'){
                    flag = 1;
                    break;
                }
                else st.pop();
            }
            
            if(st.empty()) cnt++;
        }
        
        if(flag) continue;
        else {
            answer = cnt;
            break;
        }
    }
    return answer;
}