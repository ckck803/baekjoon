#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    while (true) {
        string s;
        stack<char> st;
        getline(cin, s, '\n');

        if (s == ".") {
            break;
        }

        int i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }

            if (s[i] == '[') {
                st.push(s[i]);
            }

            if (s[i] == ')') {
                if (st.empty()) {
                    break;
                } else {
                    if (st.top() == '(') {
                        st.pop();
                    } else {
                        break;
                    }
                }
            }

            if (s[i] == ']') {
                if (st.empty()) {
                    break;
                } else {
                    if (st.top() == '[') {
                        st.pop();
                    } else {
                        break;
                    }
                }
            }
        }

        if (st.empty() && i == s.size()) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

    return 0;
}