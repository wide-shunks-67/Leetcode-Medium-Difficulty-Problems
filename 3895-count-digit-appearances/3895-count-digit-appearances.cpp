class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n= nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int x= nums[i];
            while(x!=0){
                int a= x%10;
                if(a== digit){
                    cnt++;
                }
                x=x/10;
            }
        }
        return cnt;
    }
};