#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<vector<int>> A = vector<vector<int>> (n, vector<int>(m, 0));
    vector<vector<int>> B = vector<vector<int>> (n, vector<int>(m, 0));

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> A[y][x];
        }
    }
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> B[y][x];
        }
    }
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cout << A[y][x] + B[y][x] << " ";    
        }
        cout << "\n";
    }
    return 0;
}