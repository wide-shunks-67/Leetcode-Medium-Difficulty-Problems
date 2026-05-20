class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        vector<int>prefix(n+1);
        prefix[0]=0;
        prefix[1]=cardPoints[0];
        
        for(int i=2;i<=n;i++){
            prefix[i]=prefix[i-1]+cardPoints[i-1];
        }
        int total_sum= prefix[n];

        //for 0 based indexing
        int window_size= n - k ;
        if(window_size==0)return total_sum;
        int max_sum=0;
        for(int i=0;i<=k;i++){
            int curr_win_sum = prefix[i+window_size]- prefix[i];
            max_sum= max(max_sum,total_sum - curr_win_sum);
        }
        return max_sum;
    }
};