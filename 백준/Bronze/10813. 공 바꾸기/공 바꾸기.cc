#include <iostream>
#include <vector>
using namespace std;

vector<int> basket;

void swap(int a, int b){
    int tmp = basket[a];
    basket[a] = basket[b];
    basket[b] = tmp;
}

int main(){
    //입력
    int n, m;
    cin >> n >> m;
    //입력 유효성 검사
    if(n < 1 || n > 100 || m < 1 || m > 100) return 1;
    //바구니에 공 담기
    basket = vector<int>(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        basket[i] = i;
    }
    
    //공 교환 하기
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        //입력 유효성 검검사
        if(a < 1 || a > n || b < 1 || b > n) return 1;
        if(a > b) return 1;
        
        swap(a, b);
    }
    
    for(int i = 1; i <= n; i++){
        cout << basket[i] << " ";
    }
    return 0;
}