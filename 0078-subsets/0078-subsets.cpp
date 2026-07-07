class Solution {
public:
    void solve(vector<int>nums, vector<int>output, int i, vector<vector<int>>&ans){
        if(i>=nums.size()){
            ans.push_back(output);
            return ;
        }
        solve(nums, output, i+1,ans);
        int ele= nums[i];
        output.push_back(ele);
        solve(nums,output,i+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>output;
       int index=0;
       solve(nums, output, index,ans);
       return ans;
    }
};