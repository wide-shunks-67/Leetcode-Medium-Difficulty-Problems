class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]= prefix[i-1] + nums[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(prefix[i]==k)cnt++;
            for(int j= i+1; j<n;j++){
                
                int sum= prefix[j] - prefix[i];
                if(sum==k)cnt++;
            }
        }
        return cnt;
    }
};