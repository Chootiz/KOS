#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperator(char c);
bool isNum(char c);
bool isHigherPrec(char a, char c);
int StringToInt(string str);
int Operate(int a, int b, char c);
int exponent(int a, int b);
int PostFixEval(string str);
string InfixToPostFix(string str);
string normalizePrint(string str);

int main() {
	string str;
	char c = '0';
	while (c != '2') {
		system("clear");
		cout << "-----------------[K-OS]-----------------\n\n";
		cout << "1. Evaluate Expression\n2. Exit\n\nYour Choice: ";
		cin >> c;
		switch (c) {
			case '1':
				cout << "Enter an expression to evaluate: ";
				cin >> str;
				cout << "The answer is: " << PostFixEval(InfixToPostFix(str)) << endl << endl;
				cin >> c;
				break;
		}
		
	}
}

string InfixToPostFix(string str) {
	string str1, str2 = "", str3;
	bool wasN = 0;
	int j;
	stack<char> s1;
	for (int i = 0; i < str.length(); i++) {
		wasN = 0;
		j = 0;
		while (isNum(str[i]) && i < str.length()) { str2 += str[i]; i++; j++; }
		str2 += ".";
		if (str[i] == '(') {
			s1.push(str[i]);
		}
		if (isOperator(str[i])) {
			if (!s1.empty() && isHigherPrec(str[i], s1.top())) {
				while (!s1.empty() && isHigherPrec(str[i], s1.top()) && s1.top() != '(') {
					str2 += s1.top();
					s1.pop();
				}
				s1.push(str[i]);
			}
			else {
				s1.push(str[i]);
			}
		}
		if (str[i] == ')') {
			while (s1.top() != '(') {
				str2 += s1.top();
				s1.pop();
			}
			s1.pop();
		}
	}
	while (!s1.empty()) {
		str2 += s1.top();
		s1.pop();
	}
	return str2;
}
int PostFixEval(string str) {
	string str2;
	int a, b;
	stack<int> s1;
	for (int i = 0; i < str.length(); i++) {
		str2 = "";
		if (str[i] != '.') {
			if (isNum(str[i])) {
				while (isNum(str[i])) {
					str2 += str[i]; i++;
				}
				s1.push(StringToInt(str2));
			}
			if (isOperator(str[i])) {
				a = s1.top();
				s1.pop();
				b = s1.top();
				s1.pop();
				s1.push(Operate(b, a, str[i]));
			}
		}
	}
	return s1.top();
}
bool isHigherPrec(char a, char c) {
	int prec1 = 0, prec2 = 0;
	if (a == '^') prec1 = 3;
	if (a == '*') prec1 = 2;
	if (a == '/') prec1 = 2;
	if (a == '%') prec1 = 2;
	if (a == '+') prec1 = 1;
	if (a == '-') prec1 = 1;
	if (c == '^') prec2 = 3;
	if (c == '*') prec2 = 2;
	if (c == '/') prec2 = 2;
	if (c == '%') prec2 = 2;
	if (c == '+') prec2 = 1;
	if (c == '-') prec2 = 1;
	return prec1 <= prec2;
}
bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '^' || c == '$' || c == '%' || c == '/') return 1;
	return 0;
}
bool isNum(char c) {
	if (c >= '0' && c <= '9') return 1;
	return 0;
}
int Operate(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
	if (c == '/') return a / b;
	if (c == '%') return a % b;
	if (c == '$') return a % b;
	if (c == '^') return exponent(a, b);
}
int exponent(int a, int b) {
	int ans = 1;
	while (b) {
		ans *= a;
		b--;
	}
	return ans;
}
int StringToInt(string str) {
	int a = 0;
	for (int i = 0; i < str.length(); i++) {
		a = (a * 10) + (str[i] - '0');
	}
	return a;
}
string normalizePrint(string str) {
	string str2;
	int dotCount = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			dotCount++;
		}
		if (str[i] == '.' && dotCount == 1) {
			str2 += " ";
		}
		else {
			dotCount = 0;
			str2 += str[i];
		}
	}
	return str2;
}
