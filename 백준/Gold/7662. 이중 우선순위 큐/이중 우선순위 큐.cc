#include <iostream>
#include <set>
using namespace std;

multiset<int> s;
int N;
void input(){
    cin >> N;
    
    char order;
    int number;
    for(int i = 0; i < N; i++){
        cin >> order >> number;

        if(order == 'I') s.insert(number);
        else if(order == 'D') {
            if(s.empty()) continue;
            if(number == -1) s.erase(s.begin());
            else if(number == 1) s.erase(--s.end());
        }   
    }   
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        input();
        if(s.empty()) cout << "EMPTY\n";
        else cout << *(--s.end()) << " " << *s.begin() << "\n";
        s = multiset<int>();
    }   
    return 0;
}
