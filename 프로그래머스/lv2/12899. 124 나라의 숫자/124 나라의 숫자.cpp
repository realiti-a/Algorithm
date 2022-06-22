#include <string>
#include <vector>

using namespace std;

char c[] = {'1', '2', '4'};

string solution(int n) {
    string answer = "";
    do{
        n--;
        int remain = n % 3;
        answer = c[remain] + answer;
        n /= 3;
    } while(n);
    return answer;
}