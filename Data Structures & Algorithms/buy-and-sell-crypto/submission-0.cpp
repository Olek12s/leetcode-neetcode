class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int left = 0;   // buy
        int right = 1;  // sell
        int maxProfit = 0;

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                int currentProfit = prices[right] - prices[left];
                maxProfit = std::max(maxProfit, currentProfit);
            } else {
                left = right;
            }
            right++;
        }

        return maxProfit;
    }
};