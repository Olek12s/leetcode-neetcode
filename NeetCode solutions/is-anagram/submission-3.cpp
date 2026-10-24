class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

       std::unordered_map<char, int> map;

        for (auto &c : s) {
            map[c]++;
        }

        for (auto &c : t) {
            map[c]--;
        }

        for (auto &e : map) {
            if (e.second != 0) return false;
        }
        return true;
    }
};