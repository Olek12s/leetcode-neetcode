class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dynamic(n + 1, 0);


        dynamic[0] = 0;
        dynamic[1] = 0;

        for (int i = 2; i <= n; i++) {
            dynamic[i] = min(dynamic[i - 1] + cost[i - 1], dynamic[i - 2] + cost[i-2]);
        }

        return dynamic[n];
    }
};
