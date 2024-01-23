#include <iostream>
#include <vector>
using namespace std;

vector<int> divisors;

int isCompleteNum(int num){
    divisors = vector<int> (1,1);//1 한개만 들어있는 배열 셋팅
    int sum = 1;

    for(int i = 2; i <= num/2; i++){
        if(num % i == 0){
            divisors.push_back(i);
            sum += i ;
        }
        else continue;
    }

    if(sum == num) return 1;
    else return 0;
}

int main(){
    //n이 자신을 제외한 모든 약수들의 합과 같으면, 그 수를 완전수라고 합니다.
    //6 = 1+2+3;
    //완전수라면 n을 n이 아닌 약수들의 합으로 나타내어 출력(6 = 1 + 2 + 3)
    //완전수가 아니라면 (12 is NOT perfect.) 출력.

    //입력의 마지막엔 -1
    while(true){
        int n; cin >> n;
        if(n == -1) return 0;

        //완전수인지 판단
        if(isCompleteNum(n)){
            cout << n << " = ";
            for(int i = 0; i < divisors.size() - 1; i++){
                cout << divisors.at(i) << " + ";
            }
            cout << divisors.at(divisors.size() - 1) << "\n";
        }else {
            cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}