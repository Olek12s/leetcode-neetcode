class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int numFinal = 0;
        
        for (int& num : nums) {
            numFinal ^= num;
        }
        return numFinal;
    }
};
