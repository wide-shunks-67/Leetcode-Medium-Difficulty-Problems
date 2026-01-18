class Solution {
public:
    bool check_vowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        else return false;
    }
    int vowelConsonantScore(string s) {
        
        int v=0;
        int c=0;
        for(char ch: s){
            if(ch>96 && ch<123){
                if(check_vowel(ch)){
                    v++;
                }
                else c++;
            }
        }
        if(c>0){
            return floor(v/c);
        }
        else return 0;
    }
};