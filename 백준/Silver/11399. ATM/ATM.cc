#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> people;

void input(){
    cin >> N;
    people = vector<int> (N, 0); 

    for(int i = 0; i < N; i++) cin >> people[i];
}

int main(){
    input();
    sort(people.begin(), people.end());
    
    int res = 0;
    for(int i = 0; i < N; i++){
        res += (N - i) * people[i];
    }   
    cout << res << "\n";
    return 0;
}