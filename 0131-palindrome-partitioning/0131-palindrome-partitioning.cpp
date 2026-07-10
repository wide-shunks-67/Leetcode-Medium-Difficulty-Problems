class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string>& output, int index,
               string s) {
        if (index == s.length()) {
            ans.push_back(output);
            return;
        }
        for (int i = index + 1; i <= s.length(); i++) {
            if (isPalindrome(s, index, i)) {
                output.push_back(s.substr(index, i-index));
                solve(ans, output, i, s);
                output.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right) {
        right--;
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(ans, output, 0, s);
        return ans;
    }
};