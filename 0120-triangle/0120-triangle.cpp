class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = {triangle[0][0]};
        for (int i = 1; i < n; i++) {
            vector<int> next_dp(triangle[i].size());
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    next_dp[j] = dp[0] + triangle[i][j];
                }
                else if (j == triangle[i].size() - 1) {
                    next_dp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    next_dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                }
            }
            dp = next_dp;
        }
        int m = dp.size();
        int mini = dp[0];
        for (int i = 1; i < m; i++) {
            mini = min(mini, dp[i]);
        }
        return mini;
    }
};