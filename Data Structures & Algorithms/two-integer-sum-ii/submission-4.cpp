class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        int leftPtr = 0;
        int rightPtr = numbers.size() - 1;

        while (leftPtr < rightPtr) {
            if (numbers[leftPtr] + numbers[rightPtr] < target) {
                leftPtr++;
            }
            else if (numbers[leftPtr] + numbers[rightPtr] > target) {
                rightPtr--;
            }
            else {
                result.push_back(leftPtr+1);
                result.push_back(rightPtr+1);
                break;
            }
        }
        return result;
    }
};