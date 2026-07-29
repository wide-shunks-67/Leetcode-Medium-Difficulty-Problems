class Solution {
public:
//memorization
int solve(int i, int buy, vector<int>&prices, int& fees,vector<vector<int>>dp){
    if(i==prices.size()){
        return 0;
    }
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy){
        return dp[i][buy] = max( solve(i+1,0,prices,fees,dp)-prices[i], solve(i+1,1,prices,fees,dp));
    }
    return dp[i][buy] =  max(solve(i+1,1,prices,fees,dp) + prices[i] -fees, solve(i+1,0,prices,fees,dp));
}//tabulation
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                    dp[i][buy]= max(dp[i+1][0]-prices[i], dp[i+1][1]);
                }
                else{
                    dp[i][buy]= max( dp[i+1][1] + prices[i] -fee, dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};