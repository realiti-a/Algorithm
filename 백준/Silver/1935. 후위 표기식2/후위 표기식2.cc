#include <iostream>
#include <string>
#include <stack>
using namespace std;

int dat[200] = {};
stack<double> s;
string str;

int main() {
	int N;
	cin >> N;
	cin >> str;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		dat[i + 'A'] = num;
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '*') {
			double A = s.top();
			s.pop();
			double B = s.top();
			s.pop();
			s.push(A * B);
		}
		else if (str[i] == '+') {
			double A = s.top();
			s.pop();
			double B = s.top();
			s.pop();
			s.push(B + A);
		}
		else if (str[i] == '-') {
			double A = s.top();
			s.pop();
			double B = s.top();
			s.pop();
			s.push(B - A);
		}
		else if (str[i] == '/') {
			double A = s.top();
			s.pop();
			double B = s.top();
			s.pop();
			s.push(B / A);
		}
		else {
			s.push(dat[str[i]]);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top() << "\n";
	return 0;
}