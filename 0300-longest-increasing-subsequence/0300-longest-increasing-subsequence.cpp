class Solution {
public:
//memorization
    int solve(int index, int prev_idx, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return 0;
        }
        if (dp[index][prev_idx + 1] != -1)
            return dp[index][prev_idx + 1];
        // skip
        int len = solve(index + 1, prev_idx, nums, dp);
        // take
        if (prev_idx == -1 || nums[index] > nums[prev_idx]) {
            len = max(len, 1 + solve(index + 1, index, nums, dp));
        }
        return dp[index][prev_idx + 1] = len;
    }
    //tabulation
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int>after(n + 1, 0);
        vector<int>curr(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                //not take
                int len = after[j];
                // take
                if (j == 0 || nums[i] > nums[j-1]) {
                    len = max(len, 1 + after[i+1]);
                }
                curr[j] = len;
            }
            after=curr;
        }
        return after[0];
    }
};