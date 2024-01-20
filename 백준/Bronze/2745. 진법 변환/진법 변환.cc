#include <iostream>
#include <string>

using namespace std;

int main(){
    string n; int b; cin >> n >> b;
    //b진법 수 n을 10진법으로 바꾸면
    int result = 0;
    for(char c : n){
        int num = 0;
        if(c >= 'A' && c <= 'Z') {
            num = c - 'A' + 10;
        }
        else if(c >= '0' && c <= '9'){
            num = c - '0';
        }

        result = result * b + num;
    }

    cout << result << "\n";
    return 0;
}