class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int temp = stack.top();
                stack.pop();
                result[temp] = i - temp;
            }
            stack.push(i);
        }
        return result;
    }
};