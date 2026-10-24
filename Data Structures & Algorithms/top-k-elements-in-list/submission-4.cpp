class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

        vector<pair<int, int>> pairs;
        for (auto el : map) {
            pairs.push_back({el.second, el.first});
        }

        std::sort(pairs.begin(), pairs.end(), std::greater<pair<int, int>>());

        std::vector<int> result;
        for (int i = 0; i < k && i < pairs.size(); i++) {
            result.push_back(pairs[i].second);
        }
        return result;
    }
};