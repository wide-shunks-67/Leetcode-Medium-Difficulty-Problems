class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n= nums.size();
        int sum_of_largest=0;
        int sum_of_smallest=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            int j=n-1;
            sum_of_largest+=nums[j];
            sum_of_smallest+=nums[i];
            n--;
        }
        return (sum_of_largest-sum_of_smallest);
    }
};