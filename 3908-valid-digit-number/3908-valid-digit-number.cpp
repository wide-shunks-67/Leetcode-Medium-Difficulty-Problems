class Solution {
public:
    bool validDigit(int n, int x) {
        string s= to_string(n);
        char target= x+'0';
        if(s[0]==target)return false;
        for(char c:s){
            if(c==target)return true;
        }
        return false;
    }
};