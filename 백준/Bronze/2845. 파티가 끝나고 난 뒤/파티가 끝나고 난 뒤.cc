#include <iostream>
using namespace std;
int L, P;

int news[5] = {};

void input(){
    cin >> L >> P;
    for(int i = 0; i < 5; i++){
        cin >> news[i];
    }
}

void printing(){
    int total = L * P;
    for(int i = 0; i < 5; i++){
        cout << news[i] - total << " ";
    }
    cout << "\n";
}

int main(){
    input();
    printing();
    return 0;
}