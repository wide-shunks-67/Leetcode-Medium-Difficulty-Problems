class Solution {
private:
    map<char, string> digitmap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                  {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                  {'8', "tuv"}, {'9', "wxyz"}};
    
void solve(vector<string>&ans,string current, int index, string digits){
    if(current.length()==digits.length()){
        ans.push_back(current);
        return;
    }
    string letters= digitmap[digits[index]];
    for(int i=0;i<letters.length();i++){
        current+=letters[i];
        solve(ans,current, index+1,digits);
        current.pop_back();
    }
}
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        if(digits.empty())return ans; 
        solve(ans,"",0,digits);
        return ans;
    }
};