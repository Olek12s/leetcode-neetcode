class Solution {
public:
    bool isBracketCorresponding(char a, char b) {
        if (a == '[' && b == ']') return true;
        if (a == '{' && b == '}') return true;
        if (a == '(' && b == ')') return true;
        return false;
    }

    bool isValid(string s) {
        std::stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            }
            else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
                if (!stack.empty() && isBracketCorresponding(stack.top(), s[i])) {
                    stack.pop();
                }
                else return false;
            }
        }
        if (!stack.empty()) return false;
        return true;
    }
};