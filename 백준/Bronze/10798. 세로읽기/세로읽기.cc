#include <iostream>
#define COUNT_WORDS 5
#define MAX_LENGTH_WORDS 16
using namespace std;

int main(){
    char words[COUNT_WORDS][MAX_LENGTH_WORDS] = {};

    for(int i = 0; i < COUNT_WORDS; i++){
        cin >> words[i];
    }

    for(int x = 0; x < MAX_LENGTH_WORDS; x++){
        for(int y = 0; y < COUNT_WORDS; y++){
            if(words[y][x] == 0) continue;
            cout << words[y][x];
        }
    }
    return 0;
}