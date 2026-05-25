class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            
            high= max(high,nums[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(check(nums,mid)<=threshold){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
    int check(vector<int>&nums,int div){
        int n= nums.size();
        int sum=0;
        for(int i=0;i<n;i++ ){
            sum+= (nums[i] + div - 1) / div; 
        
        }
        return sum;
    }
};