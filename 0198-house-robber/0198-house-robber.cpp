class Solution {
public:

    int rob(vector<int>& nums) {
        
        int n= nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        for(int i=2;i<n;i++){
            int left= dp[i-1];
            int right= dp[i-2]+nums[i];
            dp[i]=max(left,right);
        }
        return dp[n-1];
        
    }
};