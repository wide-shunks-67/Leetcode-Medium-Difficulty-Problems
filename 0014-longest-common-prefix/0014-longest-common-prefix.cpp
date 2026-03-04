class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        string prefix= strs[0];
        int prelen= strs[0].length();
        for(int i=1;i<n;i++){
            string s=strs[i];
            while(prelen>s.length() || prefix!= s.substr(0,prelen)){
                prelen--;
                if(prelen==0){
                    return "";
                }
                prefix=prefix.substr(0,prelen);
            }
        }
        return prefix;
    }
};