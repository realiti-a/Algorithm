#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int checkCondition(char oper, int num, int diff){
    if(oper == '=') return num == diff;
    if(oper == '>') return diff > num;
    if(oper == '<') return diff < num;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string kakaoFriends = "ACFJMNRT";
    
    do {
        int condition = 1;
        for(auto s : data){
            int firstIdx = kakaoFriends.find(s[0]);
            int secondIdx = kakaoFriends.find(s[2]);
            
            int diff = abs(firstIdx - secondIdx) - 1;
            int num = s[4] - '0';
            
            condition = checkCondition(s[3], num, diff);
            if(!condition) break;
        }
        if(condition) answer++;
    } while(next_permutation(kakaoFriends.begin(), kakaoFriends.end()));
    
    return answer;
}