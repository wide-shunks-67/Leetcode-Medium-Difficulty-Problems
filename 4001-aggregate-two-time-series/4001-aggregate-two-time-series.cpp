class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i=0,j=0;
        int n= series1.size();
        int m= series2.size();
        vector<vector<int>>ans;
        while(i<n && j<m){
            int s= series1[i][0];
             int t= series2[j][0];
             int sum= series1[i][1] + series2[j][1];
             if(s>t){
                ans.push_back({t,sum});
                j++;
             }
             else if(s<t){
                ans.push_back({s,sum});
                i++;
             }
             else{
                ans.push_back({s,sum});
                i++;
                j++;
             }
        }
        while(i<n){
            ans.push_back(series1[i++]);
        }
        while(j<m){
            ans.push_back(series2[j++]);
        }
        return ans;
    }
};