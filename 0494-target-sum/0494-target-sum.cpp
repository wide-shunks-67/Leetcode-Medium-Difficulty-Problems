class Solution {
public:
int solve(vector<int>& nums,int curr_sum, int index, int target){
    if(index==nums.size()){
        return curr_sum==target;
    }
    
    int add=solve(nums,curr_sum+nums[index],index+1,target);
    int sub=solve(nums,curr_sum-nums[index],index+1,target);
    
   return add+sub;
   
}
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(nums,0,0,target);
        
    }
};