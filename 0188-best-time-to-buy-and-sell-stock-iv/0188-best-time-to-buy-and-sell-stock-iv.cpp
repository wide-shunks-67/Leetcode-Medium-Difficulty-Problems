class Solution {
public:
int f(int index, bool buy, vector<int>&prices, int trans, vector<vector<vector<int>>>&dp){
    if(index==prices.size() || trans==0){
        return 0;
    }
    if(dp[index][buy][trans]!=-1){
        return dp[index][buy][trans];
    }
    
     if(buy){
        return dp[index][buy][trans]=max( f(index+1, 0, prices, trans,dp) - prices[index], f(index+1, 1,prices,trans,dp));
     }
     
       return dp[index][buy][trans]= max(f(index+1,1,prices,trans-1,dp) + prices[index], f(index+1, 0, prices,trans,dp));
     
     
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
         vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
         return f(0,1,prices,k,dp);
    }
    };