class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);

        int leftProd = 1;
        for (int i = 0; i < n; i++) {
            result[i] = leftProd;
            leftProd *= nums[i];
        }
        
        int rightProd = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProd;
            rightProd *= nums[i];
        }


        return result;
    }
};