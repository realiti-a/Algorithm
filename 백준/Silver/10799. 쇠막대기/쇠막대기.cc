#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input;
stack<char> s;

int main() {
	cin >> input;
	
	int result = 0, flag = 0;

	for (char c : input) {
		if (c == '(') {
			s.push(c);
			flag = 1;
		}
		else if (c == ')') {
			s. pop();
			if (flag == 1) {
				result += s.size();
				flag = 0;
			}
			else result += 1;
		}
	}
	cout << result << "\n";
	return 0;
}