class Solution {
public:
    void solve(vector<int>& c, vector<int>& o, int index,
               vector<vector<int>>& ans, int target) {
                
        if (target == 0) {
            ans.push_back(o);
            return;
        }
        for (int i = index; i < c.size(); i++) {
            if(c[i]>target)break;
            if (i > index && c[i] == c[i - 1])
                continue;

            o.push_back(c[i]);
            solve(c, o, i + 1, ans, target-c[i]);
            o.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;

        solve(candidates, output, 0, ans, target);
        return ans;
    }
};