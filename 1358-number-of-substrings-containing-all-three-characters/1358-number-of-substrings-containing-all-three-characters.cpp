class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>lseen(3,-1);
        int n= s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            lseen[s[i]-'a']=i;
            if(lseen[0]!=-1 && lseen[1]!=-1 && lseen[2]!=-1){
                cnt++;
                cnt+=min(lseen[0],min(lseen[1],lseen[2]));
            }
        }
        return cnt;
    }
};