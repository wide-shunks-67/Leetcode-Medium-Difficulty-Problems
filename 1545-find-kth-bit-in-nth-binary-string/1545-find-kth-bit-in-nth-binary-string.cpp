class Solution {
public:
    string invert(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }
    
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; i++) {
            string a= invert(s);
            s +="1";
            reverse(a.begin(),a.end()); 
            s+=a;
        }
        return s[k - 1];
    }
};