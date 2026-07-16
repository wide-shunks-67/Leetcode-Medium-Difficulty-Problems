class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n= nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>dp(n-1);
        
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n-1;i++){
            int left= dp[i-1];
            int right= dp[i-2]+nums[i];
            dp[i]= max(left,right);
        }
        vector<int>dp2(n-1);
        
        dp2[0]=nums[1];
        dp2[1]=max(dp2[0],nums[2]);
        for(int i=2;i<n-1;i++){
            int left= dp2[i-1];
            int right= dp2[i-2]+nums[i+1];
            dp2[i]= max(left,right);
        }
        return max(dp[n-2],dp2[n-2]);

    }
};