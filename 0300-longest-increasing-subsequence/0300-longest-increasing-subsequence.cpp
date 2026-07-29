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
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                //not take
                int len = dp[i+1][j];
                // take
                if (j == 0 || nums[i] > nums[j-1]) {
                    len = max(len, 1 +dp[i+1][i+1]);
                }
                dp[i][j] = len;
            }
        }
        return dp[0][0];
    }
};