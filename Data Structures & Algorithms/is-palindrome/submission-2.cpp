
class Solution {
public:
    std::string convertToAlphanumeric(std::string s) {
        std::string result;

        for (char ch : s) {
            if (std::isalnum(ch)) result.push_back(std::tolower(ch));
        }
        return result;
    }

    bool isPalindrome(string s) {
        std::string str = convertToAlphanumeric(s);
        if (str.size() == 0) return true;

        int left = 0;
        int right = str.size() - 1;

        while (left <= right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};