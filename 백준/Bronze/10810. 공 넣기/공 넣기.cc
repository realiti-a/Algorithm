#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    if(n < 1 || n > 100) return 1;
    if(m < 1 || m > 100) return 1;
    
    vector<int> arr = vector<int>(n + 1, 0);
    
    for(int x = 0; x < m; x++){
        int i, j, k;
        cin >> i >> j >> k;
        
        if(i < 1 || i > n) return 1;
        if(j < 1 || j > n) return 1;
        if(k < 1 || k > n) return 1;
        if(i > j) return 1;
        
        for(int spot = i; spot <= j; spot++){
            arr[spot] = k;
        }
    }
    
    for(int x = 1; x <= n; x++){
        cout << arr[x] << " ";
    }
    return 0;
}