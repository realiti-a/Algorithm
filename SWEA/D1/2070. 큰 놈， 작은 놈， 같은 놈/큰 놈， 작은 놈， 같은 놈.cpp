#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        int a, b;
        cin >> a >> b;
        cout << "#" << i + 1 << " ";
        if(a == b) cout << "=";
        else if(a < b) cout << "<";
        else cout << ">";
        cout << "\n";
    }   
    return 0;
}