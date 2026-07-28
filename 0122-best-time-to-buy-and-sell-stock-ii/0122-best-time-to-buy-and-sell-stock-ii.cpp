class Solution {
public:
int solve(int index, bool buy,vector<int>&prices, vector<vector<int>>&dp){
    if(index==prices.size()){
        return 0;
    }
    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }
    int profit1=0;
    int profit2=0;
    if(buy){
        profit1= max(solve(index+1,0, prices,dp) - prices[index],solve(index+1, 1 , prices, dp));
    }else{
        profit2= max(prices[index] + solve(index+1, 1, prices, dp), solve(index+1, 0,prices, dp));
    }
    return dp[index][buy]=max(profit1,profit2);
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0, 1 ,prices,dp);
    }
};