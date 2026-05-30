class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        
        int maxi=INT_MIN;
        long long sum=0;
        for(int i=0;i<n;i++){
            maxi= max(maxi,nums[i]);
            sum+=nums[i];
        }
        long long low= maxi;
        long long high= sum;
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(nums,mid)<=k){
                ans=mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
    int check(vector<int>&nums,int sum){
        int current_sum =0;
        int n= nums.size();
        int split=1;
        for(int i=0;i<n;i++){
            if(current_sum+nums[i]>sum){
                split++;
                current_sum=nums[i];
            }
            else{
                current_sum+=nums[i];
            }
        }
        return split;
    }
    
};