class Solution {
public:
    int solve(int index, int buy, vector<int>& prices) {
        if (index >= prices.size()) {
            return 0;
        }
        if (buy) {
            return max(solve(index + 1, 0, prices) - prices[index],
                       solve(index + 1, 1, prices));
        }
        return max(prices[index] + solve(index + 2, 1, prices),
                   solve(index + 1, 0, prices));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 1) {
                    dp[index][buy] =
                        max(dp[index + 1][0] - prices[index], dp[index + 1][1]);
                } else {
                    dp[index][buy] =
                        max(prices[index] + dp[index + 2][1], dp[index + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};