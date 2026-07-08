class Solution {
public:
void solve(vector<int>&candidates,int index,vector<int>output, int sum, vector<vector<int>>&ans, int target){
    if(sum>target){
        return;
    }
    if(index>=candidates.size()){
        if(sum==target){
            ans.push_back(output);
            return;
        }
        return;
    }
    
    //excluding
    solve(candidates, index+1, output,sum,ans,target);
    //including
    
    sum+=candidates[index];
    output.push_back(candidates[index]);
    solve(candidates, index, output,sum,ans,target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
         int sum=0;
         solve(candidates,0,output, sum,ans,target);
         return ans;
    }
};