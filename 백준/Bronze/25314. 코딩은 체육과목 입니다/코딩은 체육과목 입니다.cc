#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    if(N < 4 || N > 1000) return 1;
    if(N % 4) return 1;
    
    N /= 4;
    for(int i = 0; i < N; i++){
        cout << "long ";
    }
    cout << "int";
    return 0;
}