
class Solution {
public:

    // if token is digit, put it on the stack
    // if token is (+,-,*,/), pop stack twice and calculate result and put it on the stack
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for (auto& token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = stack.top();
                stack.pop();
                int left = stack.top();
                stack.pop();

                if (token == "+") stack.push(left + right);
                else if (token == "-") stack.push(left - right);
                else if (token == "*") stack.push(left * right);
                else if (token == "/") stack.push(left / right);
            }
            else {
                stack.push(std::stoi(token));
            }
        }
        return stack.top();
    }
};