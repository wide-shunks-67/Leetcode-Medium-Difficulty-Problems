class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left= 0;
        int right= n-1;
        int first=-1,last=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                first=mid;
                last=mid;
                while(first>0 && nums[first-1]==target){
                    first--;
                }
                while(last<n-1 && nums[last+1]==target){
                    last++;
                }
                break;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return {first,last};
    }
};