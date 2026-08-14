class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector< int>>& dp) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int max_cost = INT_MIN;
        for (int k = i; k <= j; k++) {
            int cost1 = solve(nums, i, k - 1, dp);
            int cost2 = solve(nums, k + 1, j, dp);
            int total = cost1 + cost2 + nums[i - 1] * nums[k] * nums[j+1];
            max_cost = max(max_cost, total);
        }
        return dp[i][j] = max_cost;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(nums, 1, n, dp);
    }
};