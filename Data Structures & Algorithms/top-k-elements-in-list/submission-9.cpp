class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

       std::priority_queue<pair<int, int>> pq;
        for (auto el : map) {
            pq.push({el.second, el.first});
        }

        std::vector<int> result;
        for (int i = 0; i < k && !pq.empty(); i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};