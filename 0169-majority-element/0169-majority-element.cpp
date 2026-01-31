class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int count=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }
            else{
                if(count>floor(n/2)){return nums[i];}
                count=1;
            }
        }
        
        return nums[n-1];
    }
};