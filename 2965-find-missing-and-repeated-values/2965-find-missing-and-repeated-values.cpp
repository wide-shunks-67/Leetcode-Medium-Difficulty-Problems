class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n= grid.size();
        map<int,int>freq;
        freq[0]++;
        for(int i=1;i<n*n +1;i++){
            freq[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }
        
        vector<int>ans(2,0);
        for(auto it:freq){
            if(it.second==0){
                ans[1]=it.first;
            }
            else if(it.second==2){
                ans[0]=it.first;
            }
        }
        return ans;
    }
};