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
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
       vector<vector<double>>after(2,vector<double>(3,0));
       vector<vector<double>>curr(2,vector<double>(3,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=1;trans<=2;trans++){
                    if(buy==1){
                        curr[buy][trans]=max( after[0][trans] - prices[index], after[1][trans]);
                    }
                    else{
                       curr[buy][trans]= max(after[1][trans-1]  + prices[index],after[0][trans]);
                    }
                }
                after=curr;
            }
        }
        return after[1][2];
    }
};