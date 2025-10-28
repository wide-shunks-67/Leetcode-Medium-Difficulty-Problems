class Solution {
private:
    map<char,string>digitmap={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
    void backtrack(const string& digits, int index, string& currentcombination,vector<string>& result){
        if(index==digits.length()){
            result.push_back(currentcombination);
            return;
        }

        char digit= digits[index];
        const string& letters= digitmap.at(digit);

        for( char letter: letters){

            currentcombination.push_back(letter);
            backtrack(digits,index+1,currentcombination,result);

            currentcombination.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string>answer;
        if(digits.empty()){
            return answer;
        }
        
        string current_combination="";
        backtrack(digits,0,current_combination,answer);
        return answer;
    }
};