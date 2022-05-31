#include <iostream>
#include <string>
using namespace std;

int main(){
    string str; cin >> str;
    for(auto c : str){
        if(c >= 'A' && c <= 'Z') c += 'a' - 'A';
        cout << c;
    }   
    return 0;
}