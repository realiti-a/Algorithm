#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    //1단계
    for(int i = 0; i < new_id.length(); i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z'){
            new_id[i] += 'a' - 'A';
        }
    }
    //2단계
    for(int i = 0; i < new_id.length(); i++){
        if(new_id[i] >= 'a' && new_id[i] <= 'z') continue;
        if(new_id[i] >= '0' && new_id[i] <= '9') continue;
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') continue;
        new_id = new_id.substr(0, i) + new_id.substr(i + 1);
        i--;
    } 
    //3단계
    int startPos = -1;
    while(true){
        startPos = new_id.find(".", startPos + 1);
        if(startPos == new_id.npos) break;
        int cnt = 0;
        for(int i = startPos; i < new_id.length(); i++){
            if(new_id[i] == '.') cnt++;
            else break;
        }
        new_id = new_id.substr(0, startPos + 1) + new_id.substr(startPos + cnt);
    }
    //4단계
    if(new_id[0] == '.') {
        new_id = new_id.substr(1);
    }
    if(new_id[new_id.length() - 1] == '.'){
        new_id = new_id.substr(0, new_id.length() - 1);
    }
    //5단계
    if(new_id == "") new_id = "a";
    //6단계
    if(new_id.length() >= 16){
        new_id = new_id.substr(0, 15);
        if(new_id[new_id.length() - 1] == '.'){
            new_id = new_id.substr(0, 14);
        }
    }
    //7단계
    while(new_id.length() < 3){
        new_id += new_id[new_id.length() - 1];
    }
    answer = new_id;
    return answer;
}