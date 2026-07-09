class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>>& ans, vector<int>& output,
               int index, int sum, int k, int target) {
        if (output.size() > k)
            return;
        if (output.size() == k) {
            if (sum == target) {
                ans.push_back(output);
                return;
            }
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            output.push_back(arr[i]);
            solve(arr, ans, output, i + 1, sum + arr[i], k, target);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr(9, 0);
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = i + 1;
        }
        vector<vector<int>> ans;
        vector<int> output;
        int sum = 0;
        solve(arr, ans, output, 0, sum, k, n);
        return ans;
    }
};