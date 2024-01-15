#include <iostream>
#include <string>
using namespace std;

int isFalindrom(string s){
    int length = s.length();
        
    for(int i = 0; i < length / 2 ; i++){
        int otherSide = length - i - 1;
        if(s[otherSide] != s[i]) return 0;
    }
    return 1;
}

int main(){
    string word; cin >> word;
    cout << isFalindrom(word);
    return 0;
}