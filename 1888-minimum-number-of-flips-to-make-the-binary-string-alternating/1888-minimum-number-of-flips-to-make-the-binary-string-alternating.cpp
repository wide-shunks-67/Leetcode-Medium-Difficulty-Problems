class Solution {
public:
    
    int minFlips(string s) {
        int min_ops= INT_MAX;
        int n= s.length();
        string t= s+s;
        string p1="";
        string p2="";
        for(int i=0;i<t.length();i++){
            p1+= i%2==0 ?'0':'1';
            p2+= i%2==0 ?'1':'0';
        }
        int diff1=0;
        int diff2=0;
        for(int i=0;i<t.length();i++){
           if(t[i]!=p1[i])diff1++;
           if(t[i]!=p2[i])diff2++;
           if(i>=n){
            if(t[i-n]!=p1[i-n])diff1--;
            if(t[i-n]!=p2[i-n])diff2--;
           }
           if(i>=n-1){
            min_ops= min({min_ops,diff1,diff2});
           }
        }
        return min_ops;
    }
};