class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int l=0;
        int len=0;
        int zers_flip=0;
        for(int r=0;r<n;r++){
            if(nums[r]==0){
                zers_flip++;
            }
            while(zers_flip>k){
                if(nums[l]==0){
                    zers_flip--;
                }
                l++;
            }
            len= max(len,r- l + 1);
            
        }
        return len;
    }
};