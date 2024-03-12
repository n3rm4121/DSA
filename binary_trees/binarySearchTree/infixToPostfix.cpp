#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperand(char s) {
    return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
}

int precedence(char s) {
    switch (s) {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    }
    return -1;
}

string infixToPostfix(string exp) {
    stack<char> st;
    string postfix;
    for (int i = 0; i < exp.size(); i++) {
        if (isOperand(exp[i])) {
            postfix.push_back(exp[i]);
        } else if (exp[i] == '(') {
            st.push(exp[i]);
        } else if (exp[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop(); // Pop '('
        } else {
            while (!st.empty() && precedence(exp[i]) <= precedence(st.top())) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while (!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}

int main() {
    string exp = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(exp);
    return 0;
}
