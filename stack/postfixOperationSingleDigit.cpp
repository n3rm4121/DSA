// for single digit
// e.g. "231*+9-"

#include <iostream>
#include <stack>
#include <set>
#include <string>
using namespace std;

set<char> op = {'*', '+', '/', '-'};

void display(stack<int> test) {
    cout << "Stack: ";
    while (!test.empty()) {
        cout << test.top() << " ";
        test.pop();
    }
}

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
    int a, b;
    for (auto& s : exp) {
        if (s == ' ') {
            continue;
        } else if (!op.count(s)) {
            int temp = s - '0';
            operands.push(temp);
            // display(operands);
        } else if (op.count(s)) {
            a = operands.top();
            operands.pop();
            b = operands.top();
            operands.pop();
            int final = operation(s, a, b);
            operands.push(final);
        }
    }
    return operands.top();
}

int main() {
    cout << "Enter your single digit postfix Expression: ";
    string exp;
    getline(cin, exp);

    cout << "Answer: " << postfix(exp);
    return 0;
}
