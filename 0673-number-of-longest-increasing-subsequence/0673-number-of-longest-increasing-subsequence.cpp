class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
         int n = nums.size();
        vector<int> dp(n, 1);
        vector<int>cnt(n,1);
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[i]> nums[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    cnt[i]=cnt[j];
                }
                else if(dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j]; 
                }
            }
            max_len = max(max_len, dp[i]);
        }
        int nos=0;
        for(int i=0;i<n;i++){
            if(dp[i]==max_len){
                nos+=cnt[i];
            }
        }
        return nos;
    }
};