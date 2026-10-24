class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());

        int highest = 1;
        int counter = 1;

        for (int i = 1; i < nums.size(); i++) {
            int previous = nums[i - 1];
            int current = nums[i];

            if (current == previous) continue;
            if (current == previous + 1) counter++;
            else {
                counter = 1;
            }
            highest = std::max(counter, highest);
        }
        return std::max(counter, highest);
    }
};
