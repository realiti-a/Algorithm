#include <string>
#include <vector>

using namespace std;

string toBinary(int n){
    string res = "";
    while(n){
        res = (char)(n % 2 + '0') + res;
        n /= 2;
    }
    return res;
}

int toDex(string s){
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        res = res * 2 + (s[i] - '0');
    }
    return res;
}

int countOne(string s){
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') cnt++;
    }
    return cnt;
}

int solution(int n) {
    string binN = toBinary(n);
    int count1N = countOne(binN);
    
    for(int i = 1; i <= n; i++){
        string binI = toBinary(n + i);
        int countI = countOne(binI);
        if(countI == count1N) {
            return n + i;
        }
    }
}