class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ask(nums,goal) - ask(nums,goal-1);
    }
    int ask(vector<int>nums,int g){
        if(g<0)return 0;
        int n= nums.size();
        int l=0;
        int sum=0;
        int cnt=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>g){
                sum-=nums[l];
                l++;
            }
            cnt+=(r - l + 1);
        }
        return cnt;
    }
};