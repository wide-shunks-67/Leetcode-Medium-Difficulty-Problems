class Solution {
public:
    int minLength(vector<int>& nums, int k) {
      int n= nums.size();
      int l=0;
      int r=0;
      int sum=0;
      int min_length=INT_MAX;
      unordered_map<int,int>freq;
      while(r<n){
        freq[nums[r]]++;
        if(freq[nums[r]]==1){
            sum+=nums[r];
        }
        while(sum>=k){
            min_length= min(min_length, r - l + 1);
            freq[nums[l]]--;

            if(freq[nums[l]]==0){
                sum-=nums[l];
            }

            l++;
        }
        r++;
      }  
      if(min_length== INT_MAX){
        return -1;
      }
      else{
        return min_length;
      }
    }
};