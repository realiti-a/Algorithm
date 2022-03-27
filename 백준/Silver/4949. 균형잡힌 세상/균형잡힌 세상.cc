#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> stack;

void push(char c) {
	stack.push_back(c);
}

void pop() {
	if (stack.size() == 0) return ;
	stack.pop_back();
}

char top() {
	if (stack.size() == 0) return -1;
	return stack.back();
}

bool isEmpty() {
	return stack.empty();
}

int isOkay(string s){
	stack.resize(0);
	for (auto ch : s) {
		if (ch == '[' || ch == '(') push(ch);
		else if (ch == ']') {
			if (top() == '[') pop();
			else return 0;
		}
		else if (ch == ')') {
			if (top() == '(') pop();
			else return 0;
		}
	}

	return isEmpty();
}

int main() {
	string s;
	while (true) {
		getline(cin, s);
		if (s == ".") break;
		if (isOkay(s)) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}