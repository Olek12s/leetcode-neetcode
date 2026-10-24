class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        std::unordered_map<string, vector<string>> map;

        for (string& str : strs) {
           int count[26] = {0};

            for (char& c : str) {
                count[c - 'a']++;
            }

            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "^" + to_string(count[i]);
            }
            map[key].push_back(str);
        }

        for (auto& it : map) {
            result.push_back(it.second);
        }
        return result;
    }
};
