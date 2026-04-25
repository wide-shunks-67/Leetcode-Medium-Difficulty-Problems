class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum_a=0;
        long long sum_b=0;
        int idx=-1;
        int  n= nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                sum_a+=nums[i-1];
            }
            else{
                
                idx= i-1;
                break;
            }
        }
        for(int j= idx + 1;j<n;j++){
            sum_b+=nums[j];
        }
        if(sum_a>sum_b)return 0;
        else if(sum_b>sum_a)return 1;
        else return -1;
    }
};