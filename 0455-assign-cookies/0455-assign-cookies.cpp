class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int n= g.size();
        int m= s.size();
        int j=0;
        int i=0;
        int cnt=0;
        while(i<m & j<n){
            if(s[i]>=g[j]){
                j++;i++;
                cnt++;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};