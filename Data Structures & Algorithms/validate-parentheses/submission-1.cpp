class Solution {
public:
    bool isValid(string s) {
        stack<char> open_brackets;
        for(char &ch : s) {
            if (ch == '[' || ch == '{' || ch == '(') {
                open_brackets.push(ch);
            } else if (ch == ']') {
                if (open_brackets.empty()) return false;
                if (open_brackets.top() != '[') return false;
                open_brackets.pop();
                continue;
            } else if (ch == '}') {
                if (open_brackets.empty()) return false;
                if (open_brackets.top() != '{') return false;
                open_brackets.pop();
                continue;
            } else if (ch == ')') {
                if (open_brackets.empty()) return false;
                if (open_brackets.top() != '(') return false;
                open_brackets.pop();
                continue;
            }
        }
        if (!open_brackets.empty()) return false;
        
        return true;
    }
};