class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int m = intervals[0].size();
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        vector<int>prev=intervals[0];
        for(int i=1;i<n;i++){
            vector<int>interval= intervals[i];
            if(interval[0]<=prev[1]){
                prev[1]=max(interval[1],prev[1]);
            }
            else{
                res.push_back(prev);
                prev=interval;
            }
        }
        res.push_back(prev);
        return res;
        }
    };