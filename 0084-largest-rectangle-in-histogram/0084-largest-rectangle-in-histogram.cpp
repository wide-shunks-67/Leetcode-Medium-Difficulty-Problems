class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        stack<int>nse;
        stack<int>pse;
        vector<int>nse_idx(n,n);
        vector<int>pse_idx(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!nse.empty() && heights[nse.top()]>=heights[i]){
                nse.pop();
            }
            if(!nse.empty()){
                nse_idx[i]=nse.top();
            }
            nse.push(i);
        }
        for(int i=0;i<n;i++){
            while(!pse.empty() && heights[pse.top()]>=heights[i]){
                pse.pop();
            }
            if(!pse.empty()){
                pse_idx[i]=pse.top();
            }
            pse.push(i);
        }

        int ans=-1;
        for(int i=0;i<n;i++){
            int width= (i- pse_idx[i]) + (nse_idx[i]- i ) - 1;
            int area= width * heights[i];
             ans= max(ans,area);
        }
        return ans;
    }
};