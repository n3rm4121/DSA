// for multi-digit;
// e.g. "100 200 + 2 / 5 * 7 +" 

#include <iostream>
#include <stack>
#include <set>
#include <string>
using namespace std;

set<char> op = {'*', '+', '/', '-'};

int operation(char s, int a, int b) {
    switch (s) {
        case '+':
            return b + a;
        case '-':
            return b - a;
        case '*':
            return b * a;
        case '/':
            if (a != 0) // Check for division by zero
                return b / a;
            else {
                cerr << "Error: Division by zero!" << endl;
                exit(1);
            }
        default:
            return 0;
    }
}

int postfix(string exp) {
    std::stack<int> operands;
    string token;
    for (char s : exp) {
        if (s == ' ') {
            if (!token.empty()) {
                int temp = stoi(token);
                operands.push(temp);
                token.clear();
            }
        } else if (!op.count(s)) {
            token += s;
        } else if (op.count(s)) {
            if (!token.empty()) {
                int temp = stoi(token);
                operands.push(temp);
                token.clear();
            }
            if (!operands.empty()) {
                int a = operands.top();
                operands.pop();
                int b = operands.top();
                operands.pop();
                int result = operation(s, a, b);
                operands.push(result);
            }
        }
    }
    if (!token.empty()) {
        int temp = stoi(token);
        operands.push(temp);
    }
    return operands.top();
}


int main() {
    cout << "Enter your multi-digit postfix Expression: (e.g. 100 200 + 2 / 5 * 7 +) : ";
    string exp;
    getline(cin, exp);
    // string exp = "100 200 + 2 / 5 * 7 +";
    cout << "Answer: " << postfix(exp);
    return 0;
}
