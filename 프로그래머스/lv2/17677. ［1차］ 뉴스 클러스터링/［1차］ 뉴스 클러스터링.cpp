#include <string>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m1;
map<string, int> m2;

int notOkay(char c){
    if((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) return 1;
    return 0;
}

char toLower(char c){
    if(c >= 'A' && c <= 'Z') c += 'a' - 'A';
    return c;
}

int solution(string str1, string str2) {
    int answer = 0;
    int m1Size = 0, m2Size = 0;
    // 잘라서 multiset에 넣기
    for(int i = 0; i < str1.length() - 1; i++){
        char c = str1[i];
        char d = str1[i + 1];
        
        if(notOkay(c) || notOkay(d)) continue;
        
        c = toLower(c);
        d = toLower(d);
        
        m1Size++;
        string next = "";
        next += c; next += d;
        if(m1.find(next) == m1.end()) m1[next] = 1;
        else m1[next]++;
    }    
    
    for(int i = 0; i < str2.length() - 1; i++){
        char c = str2[i];
        char d = str2[i + 1];
        
        if(notOkay(c) || notOkay(d)) continue;
        
        c = toLower(c);
        d = toLower(d);
        
        m2Size++;
        string next = ""; next += c; next += d;
        if(m2.find(next) == m2.end()) m2[next] = 1;
        else m2[next]++;
    }
    
    int sameCnt = 0;
    
    for(auto iter : m1){
        string s = iter.first;
        if(m2.find(s) == m2.end()) continue;
        int small = m1[s] < m2[s]? m1[s] : m2[s];
        sameCnt += small;
    }
    
    
    int unionSize = m1Size + m2Size - sameCnt;
    if(!unionSize) return 65536;
    
    answer = sameCnt * 65536 / unionSize;
    return answer;
}