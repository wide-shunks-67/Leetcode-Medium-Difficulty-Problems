class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1;
        int high = 0;
        for (int pile : piles) {
            high = max(high, pile);
        }
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    bool can(vector<int>& p, int m, int h) {
        long long hours = 0;
        for (int pile : p) {
            hours += (pile + m - 1) / m;
        }
        return hours <= h;
    }
};