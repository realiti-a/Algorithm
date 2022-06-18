#include <iostream>
#include <algorithm>
using namespace std;

int arr[9] = {}; 
int visited[9] = {}; 
void combi(int level, int start){
    if(level == 7){ 
        int sum = 0;
        for(int i = 0; i < 9; i++){
            if(visited[i]) sum += arr[i];
        }   
        if(sum == 100){
            for(int i = 0; i < 9; i++) {
                if(visited[i]) cout << arr[i] << "\n";
            }   
            exit(0);
        }   
        return;
    }   
    for(int i = start; i < 9; i++){
        visited[i] = 1;
        combi(level + 1, i + 1); 
        visited[i] = 0;
    }   
}

int main(){
    for(int i = 0; i < 9; i++) cin >> arr[i];
    sort(arr, arr + 9); 
    combi(0, 0); 
    return 0;
}