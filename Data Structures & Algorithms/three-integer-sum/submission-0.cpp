class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // skip duplicates for 1st element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // 2 pointers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (currentSum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // skip duplicates for 2nd element
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    
                    // skip duplicates for 3rd element
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (currentSum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return res;
    }
};