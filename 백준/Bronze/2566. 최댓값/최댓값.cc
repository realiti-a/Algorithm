#include <iostream>
using namespace std;

int main(){
    int arr[9][9] = {};
    
    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++) cin >> arr[y][x];
    }

    int maxY = 0, maxX = 0;
    int max = arr[maxY][maxX];

    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            if(arr[y][x] > max){
                maxY = y;
                maxX = x;
                max = arr[y][x];
            }
        }
    }

    cout << max << "\n";
    cout << maxY + 1 << " " << maxX + 1 << "\n";
    return 0;
}