#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    int A, B;
    cin >> A >> B;
    
    int sequence = 1;
    for(int i = 1; i <= 500; i++){
        for(int j = 0; j < i; j++){
            if(sequence >= A && sequence <= B) sum += i;
            if(sequence > B) break;
            sequence++;
        }
        if(sequence > B) break;
    }
    
    cout << sum << "\n";
    return 0;
}
