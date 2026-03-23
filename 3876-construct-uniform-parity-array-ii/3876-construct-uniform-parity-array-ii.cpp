class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n= nums1.size();
        int cnt_odd=0;
        int cnt_even=0;
        int mini= INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0)cnt_even++;
            else {
                mini= min(mini,nums1[i]);
                cnt_odd++;
                }
        }
        if(cnt_even==n || cnt_odd==n)return true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                if(nums1[i]<mini)return false;
            }
        }
        return true;
    }
};