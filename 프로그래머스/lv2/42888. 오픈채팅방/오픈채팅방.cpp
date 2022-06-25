#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, string> m;

void getInfo(string s) {
    string order = s.substr(0, 5);
    //채팅방 퇴장
    if(order == "Leave") return;
    else if(order == "Enter") {
        //채팅방 입장
        int nextSpace = s.find(" ", 6);
        string id = s.substr(6, nextSpace - 6);
        string nickname = s.substr(nextSpace + 1);
        m[id] = nickname;
    }
    else {
        //닉네임 변경 "change"
        int nextSpace = s.find(" ", 7);
        string id = s.substr(7, nextSpace - 7);
        string nickname = s.substr(nextSpace + 1);
        m[id] = nickname;
    }
}

string getNick(string s){
    int space[3] = {};
    //공백 간격 구하기
    for(int i = 1; i < 3; i++) space[i] = s.find(" ", space[i - 1] + 1);
    string id = s.substr(space[1] + 1, space[2] - space[1] - 1);
    return m[id];
}

vector<string> solution(vector<string> records) {
    vector<string> answer;
    
    for (auto record : records) getInfo(record);
    
    for (auto record : records){
        string nick = getNick(record);
        if(record[0] == 'E') answer.push_back(nick + "님이 들어왔습니다.");
        else if(record[0] == 'L') answer.push_back(nick + "님이 나갔습니다.");
        else continue;
    }
    return answer;
}