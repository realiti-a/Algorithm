#include <iostream>
#include <vector>
using namespace std;

vector<int> list;

void swap(int a, int b){
    int tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
}

void flipList(int a, int b){
    int start = a;
    int sum = a + b;
    int middle = sum / 2;
    
    for(int i = a; i <= middle; i++){
        //두 수의 자리 바꾸기
        swap(i, sum - i);
    }
}

void printList(){
    list.erase(list.begin());
    for(auto a : list) cout << a << " ";
    cout << "\n";
}

int main(){
    int n, m;
    cin >> n >> m;
    //바구니 크기 셋팅
    list = vector<int>(n + 1, 0);
    
    //바구니에 순서대로 공 담기
    for(int i = 1; i <= n; i++) list[i] = i;
    
    //바구니에 swap할 범위 입력 받기
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        
        flipList(a, b);
    }
    
    printList();
    
    return 0;
}