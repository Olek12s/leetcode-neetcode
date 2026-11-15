class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;

        while (set.find(n) == set.end()) {
            set.insert(n);
            n = sum(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }

    int sum(int n) {
        int res = 0;

        while (n > 0) {
            int digit = n % 10;
            digit = digit * digit;
            res += digit;
            n /= 10;
        }
        return res;
    }
};