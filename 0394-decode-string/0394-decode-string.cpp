class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ']'){ // it should be '' for char check
                st.push(string(1, s[i])); // Make it string befor push or you get error
            } else {
                string innertext = "";
                while(!st.empty() && st.top() != "[") { // it should be "" for string check
                    innertext = st.top() + innertext; st.pop();
                }
                st.pop(); // remove '['

                string num = "";
                while(!st.empty() && isdigit(st.top()[0])){ // [0] use this to make it char for digit check
                    num = st.top() + num; st.pop();
                }

                int k = stoi(num);
                string expendedtext = "";
                while(k--) {
                    expendedtext += innertext;
                }
                st.push(expendedtext);
            }
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop(); // Don't forget pop() while using while loop
        }
        return res;
    }
};