class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans(m, 0);
        int row = 0;
        int answer = -1;
        while (row < n) {
            for (int i = 0; i < m; i++) {
                ans[i] = matrix[row][i]=='1'? ans[i]+1:0;
            }
            
            stack<int> nse;
            stack<int> pse;
            vector<int> nse_idx(m, m);
            vector<int> pse_idx(m, -1);
            for (int i = m - 1; i >= 0; i--) {
                while (!nse.empty() && ans[nse.top()] >= ans[i]) {
                    nse.pop();
                }
                if (!nse.empty()) {
                    nse_idx[i] = nse.top();
                }
                nse.push(i);
            }
            for (int i = 0; i < m; i++) {
                while (!pse.empty() && ans[pse.top()] >= ans[i]) {
                    pse.pop();
                }
                if (!pse.empty()) {
                    pse_idx[i] = pse.top();
                }
                pse.push(i);
            }

            
            for (int i = 0; i < m; i++) {
                int width = (i - pse_idx[i]) + (nse_idx[i] - i) - 1;
                int area = width * ans[i];
                answer = max(answer, area);
            }
            row++;
        }
        return answer;
    }
};