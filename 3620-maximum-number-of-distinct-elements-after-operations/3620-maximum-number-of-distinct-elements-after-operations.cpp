class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0,prev=INT_MIN;
        for(int num:nums){
            int current= min(max(num-k,prev+1),num+k);
            if(current>prev){
                count++;
                prev=current;
            }
        }
        return count;
    }
};