
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int maxK = 0;   // right
        int K = 1;

        // find max
        for (int i = 0; i < piles.size(); i++) {
            maxK = std::max(maxK, piles[i]);
        }

        // bin search
        while (left <= maxK) {
            int mid = (left + maxK) / 2;

            long long hoursNeeded = 0;
            for (int i = 0; i < piles.size(); i++) {
                hoursNeeded += (piles[i] + mid - 1) / mid;
            }

            if (hoursNeeded <= h) {
                K = mid;           // eating fast enough
                maxK = mid - 1;   // check left for potentially better K
            } else {
                left = mid + 1;    // eatnig too slow
            }
        }
        return K;
    }
};