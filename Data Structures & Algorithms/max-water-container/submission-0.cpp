class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int currentWidth = right - left;
            int currentHeight = std::min(heights[left], heights[right]);
            int currentWater = currentWidth * currentHeight;

            maxWater = std::max(maxWater, currentWater);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};