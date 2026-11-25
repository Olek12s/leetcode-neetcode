class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int rs = result.size();
            for (int j = 0; j < rs; j++) {
                vector<int> subset = result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }
        return result;
    }
};
