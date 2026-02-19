class Solution {
public:
    int countBinarySubstrings(string s) {
       int n= s.length();
       int grps=0;
       for(int i=0;i<n;i++){
        int count=1;
        while(s[i]==s[i+1]){
            count++;
            i++;
        }
        int j=i+1;
        while(s[j]!=s[i] && j<n){
            if(count>0){
                count--;
                grps++;
                 j++;
            }
            else break;
        }
       } 
       return grps;
    }
};