#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string site, password;
    for(int i = 0; i < N; i++){
        cin >> site >> password;
        m[site] = password;
    }   

    string input;
    for(int i = 0; i < M; i++){
        cin >> input;
        cout << m[input] << "\n";
    }   

    return 0;
}