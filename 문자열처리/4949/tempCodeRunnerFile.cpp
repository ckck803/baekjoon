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