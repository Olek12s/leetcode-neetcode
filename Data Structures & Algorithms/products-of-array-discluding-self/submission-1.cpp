class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);
        std::vector<int> prefixProd(n);
        prefixProd[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefixProd[i] = prefixProd[i - 1] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                int prod = 1;
                for (int j = 0; j < nums.size(); j++) {
                    if (i != j) prod *= nums[j];
                }
                result[i] = prod;
            }
            else {
                result[i] = prefixProd[nums.size() - 1] / nums[i];
            }
        }
        return result;
    }
};