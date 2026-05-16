class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int max_len=INT_MIN;
        int curr_len=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                curr_len++;
            }
            else{
                max_len= max(max_len,curr_len);
                curr_len=0;
            }
        }
        max_len= max(max_len,curr_len);
        return max_len;
    }
};