#include <string>
#include <vector>

using namespace std;

int getOne(string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '1') count++;
    }
    return count;
}

string toBin(int n){
    string res = "";
    
    while(n){
        res = res + (char)(n % 2 + '0');
        n /= 2;
    }
    
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroCnt = 0, transCnt = 0;
    
    while(s != "1"){
        int oneCnt = getOne(s);
        zeroCnt += s.length() - oneCnt;
        
        s = toBin(oneCnt);
        transCnt++;
    }
    
    answer.push_back(transCnt);
    answer.push_back(zeroCnt);
    
    return answer;
}