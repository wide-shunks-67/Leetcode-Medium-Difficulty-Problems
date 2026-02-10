class Solution {
public:
    int residuePrefixes(string s) {
        int n= s.length();
        int cnt=0;
        set<char>pre;
        for(int i=0;i<n;i++){
            pre.insert(s[i]);
            if(pre.size() == (i+1)%3)cnt++;
            if(pre.size()>=3)return cnt;
        }
        return cnt;
    }
};