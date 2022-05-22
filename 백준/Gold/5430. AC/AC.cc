#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

deque<int> dq; 
string arr, p;

void makeArr(int N){ 
    if(N == 0) return;
    int start = 1;
    while(true){
        int end = arr.find(",", start);
        if (end == -1) end = arr.length();
        dq.push_back(stoi(arr.substr(start, end - start)));
        start = end + 1;
        if(start >= arr.length()) break;
    }   
}

int run(){
    vector<int> result;
    int sign = 1;
    for(auto order : p){ 
        if(order == 'D'){
            if(dq.empty()) return 1;
            if(sign == 1){ 
                dq.pop_front();
            }   
            else if(sign == -1){
                dq.pop_back();
            }   
        }   
        else if(order == 'R') sign *= -1; 
    }   

    cout << "[";
    while(!dq.empty()){
        if(sign == 1){ 
            cout << dq.front();
            dq.pop_front();
        }   
        else if(sign == -1){
            cout << dq.back();
            dq.pop_back();
        }   
        if(dq.empty()) break;
        cout << ",";
    }   
    cout << "]\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> p >> N;
        cin >> arr;
        makeArr(N);
        if(run()) cout << "error\n";
    }
    return 0;
}