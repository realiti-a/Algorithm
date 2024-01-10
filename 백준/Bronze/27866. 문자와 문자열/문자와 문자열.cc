#include <iostream>
#include <string>
using namespace std;

int main(){
    string S; cin >> S;
    int i; cin >> i;

    cout << S.at(i - 1);
    return 0;
}