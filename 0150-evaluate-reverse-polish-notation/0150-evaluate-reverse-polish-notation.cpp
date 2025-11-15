#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (size_t i = 0; i < tokens.size(); ++i) {
            string s = tokens[i];
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                if (s == "+") st.push(op1 + op2);
                else if (s == "-") st.push(op1 - op2);
                else if (s == "*") st.push(op1 * op2);
                else st.push(op1 / op2);
            } else {
                st.push(stoi(s));
            }
        }
        return st.empty() ? 0 : st.top();
    }
};
