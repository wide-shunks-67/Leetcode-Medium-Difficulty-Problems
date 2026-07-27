class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int>max_future(n,-1);
        max_future[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            max_future[i]= max(max_future[i+1],prices[i]);
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi= max(maxi, max_future[i]-prices[i]);
        }
        return maxi;
    }
};