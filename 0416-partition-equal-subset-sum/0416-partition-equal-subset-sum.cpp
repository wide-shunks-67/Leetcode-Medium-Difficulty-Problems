class Solution {
public:
bool solve(vector<int>&nums, vector<vector<int>>&dp, int index, int k){
    if(k==0)return true;
    if(index>=nums.size())return false;
    if(dp[index][k]!=-1)return dp[index][k];
    bool include=false;
    if(nums[index]<=k){
        include= solve(nums,dp,index+1,k-nums[index]);
    }
    bool exclude= solve(nums,dp,index+1,k);
    return dp[index][k]=include||exclude;
}
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        vector<vector<int>>dp(n,vector<int>(sum/2 + 1,-1));
        return solve(nums,dp,0,sum/2);
    }
};