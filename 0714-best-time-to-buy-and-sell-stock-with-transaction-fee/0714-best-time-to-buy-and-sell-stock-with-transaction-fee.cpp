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
}//space optimized tabulation
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<int>after(2,0);
        vector<int>curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                    curr[buy]= max(after[0]-prices[i], after[1]);
                }
                else{
                    curr[buy]= max( after[1] + prices[i] -fee, after[0]);
                }
            }
            after=curr;
        }
        return after[1];
    }
};