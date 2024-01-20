#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, b; cin >> n >> b;
    string result = "";
    while(n > 0){
        int remain = n % b;
        char c = 0;
        if(remain >= 10 && remain <= 35){
            c = 'A' + remain - 10;
        }else if(remain >= 0 && remain <= '9'){
            c = '0' + remain;
        }        
        result = c + result;
        n /= b;
    }

    cout << result;
    return 0;
}