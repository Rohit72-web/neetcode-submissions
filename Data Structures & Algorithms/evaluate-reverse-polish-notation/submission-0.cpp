class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(int i = 0; i < tokens.size(); i++) {

            if(tokens[i] != "+" && tokens[i] != "-" &&
               tokens[i] != "*" && tokens[i] != "/") {

                st.push(tokens[i]);
            }
            else {
                int op1 = stoi(st.top());
                st.pop();

                int op2 = stoi(st.top());
                st.pop();

                string op = tokens[i];

                if(op == "+")
                    st.push(to_string(op2 + op1));

                else if(op == "-")
                    st.push(to_string(op2 - op1));

                else if(op == "*")
                    st.push(to_string(op2 * op1));

                else
                    st.push(to_string(op2 / op1));
            }
        }

        return stoi(st.top());
    }
};