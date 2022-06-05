#include <iostream>
using namespace std;

int cnt;
int N, S;
int sequence[20];

void run(int start, int sum){
    if(sum == S && start != 0) cnt++;
    for(int i = start; i < N; i++){
        run(i + 1, sum + sequence[i]);
    }   
}

int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> sequence[i];
    cnt = 0;
    run(0, 0); 
    cout << cnt << "\n";
    return 0;
}