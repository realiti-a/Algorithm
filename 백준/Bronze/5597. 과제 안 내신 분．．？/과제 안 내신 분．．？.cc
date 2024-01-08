#include <iostream>
using namespace std;

int assignments[31] = {};

int main(){
    for(int i = 0; i < 28; i++){
        int student; cin >> student;
        assignments[student]++;
    }
    
    for(int i = 1; i <= 30; i++){
        if(assignments[i]) continue;
        cout << i << " \n";
    }
    return 0;
}