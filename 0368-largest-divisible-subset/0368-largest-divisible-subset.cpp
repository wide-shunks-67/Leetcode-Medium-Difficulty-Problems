class Solution {
public:
    void solve(int curr, int prev, vector<int>& nums, vector<int>&ans, vector<int>&output, int &max_len) {
        if (curr == nums.size()) {
            if(output.size()>max_len){
                ans=output;
                max_len=output.size();
            }
            return ;
        }
        solve(curr+1,prev,nums,ans,output,max_len);
        if(prev==-1 || (nums[curr]%nums[prev]==0)){
            output.push_back(nums[curr]);
            solve(curr+1,curr, nums,ans,output,max_len);
            output.pop_back();
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int max_len=1;
        int max_idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j] + 1 > dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>max_len){
                max_len= dp[i];
                max_idx=i;
            }
        }
        vector<int>ans;
        while(max_idx!=-1){
            ans.push_back(nums[max_idx]);
            max_idx=prev[max_idx];
        }
        return ans;
    }
};