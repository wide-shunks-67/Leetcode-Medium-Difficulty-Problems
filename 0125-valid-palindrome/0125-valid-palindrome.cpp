class Solution {
public:
    bool isPalindrome(string s) {
     string ans;
     for(char c:s){
        if((c>='a' && c<='z') || (c >= '0' && c <= '9')){
            ans+=c;
        }
        else if(c>='A' && c<='Z'){
            ans+= (c+ 32);
        }
        else continue;
     }   
     int left= 0;
     int right= ans.length()-1;
     while(left<=right){
        if(ans[left]==ans[right]){
            left++;
            right--;
        }
        else return false;
     }
     return true;
    }
};