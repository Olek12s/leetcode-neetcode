class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (int i = 0; i < strs.size(); i++) {
            result += strs[i].size();
            result += "^";
            result += strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.size()) {
            int len = static_cast<unsigned char>(s[i]);

            string current = s.substr(i + 2, len);
            result.push_back(current);

            i = i + 2 + len;
        }

        return result;
    }
};