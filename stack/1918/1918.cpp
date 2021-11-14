#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    string result;
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            result += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else if (s[i] == '*' || s[i] == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        } else {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << '\n';
    return 0;
}