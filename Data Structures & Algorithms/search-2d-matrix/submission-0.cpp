class Solution {
private:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return -1;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int cols = matrix[0].size();
        int targetRow = -1;

        // search correct row
        while (top <= bottom) {
            int midRow = (top + bottom) / 2;

            if (target >= matrix[midRow][0] && target <= matrix[midRow][cols - 1]) {
                targetRow = midRow;
                break;
            }
            else if (target < matrix[midRow][0]) {
                bottom = midRow - 1;
            }
            else {
                top = midRow + 1;
            }
        }
        if (targetRow == -1) {
            return false;
        }
        return search(matrix[targetRow], target) != -1;
    }
};