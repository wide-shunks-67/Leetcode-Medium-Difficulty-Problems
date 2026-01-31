class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long n= nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        long long cnt=1;
        for(long long i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else{
                if(cnt>n/3)ans.push_back(nums[i]);
                cnt=1;
            }
        }
        if(cnt>n/3)ans.push_back(nums[n-1]);
        return ans;
    }
};