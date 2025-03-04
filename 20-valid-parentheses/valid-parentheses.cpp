class Solution {
public:
    bool isPair(char s1, char s2){  
        if(s1 == '(' && s2 == ')') return true;
        if(s1 == '{' && s2 == '}') return true;
        if(s1 == '[' && s2 == ']') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char>stack;
        for(int i = 0; i < s.length() ; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push(s[i]);
            } else {
                if(!stack.empty() && isPair(stack.top(),s[i])){
                    stack.pop();
                }else {
                    return false;
                }
            }
        }
        if(stack.empty()){
            return true;
        } else {
            return false;
        }
    }
};