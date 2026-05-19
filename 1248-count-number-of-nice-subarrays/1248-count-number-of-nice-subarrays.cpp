class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        return ask(nums,k) - ask(nums,k-1);
    }
    int ask(vector<int>nums,int g){
        
        int l=0;
        int n= nums.size();
        int sum=0;
        int cnt=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>g){
                sum-= nums[l];
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
};