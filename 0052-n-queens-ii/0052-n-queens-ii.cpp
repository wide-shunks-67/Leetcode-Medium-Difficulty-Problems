class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int d_row = row;
        int d_col = col;
        while (row >= 0 && col >= 0) {
            if (board[row--][col--] == 'Q')
                return false;
        }
        row = d_row;
        col = d_col;
        while (col >= 0) {
            if (board[row][col--] == 'Q')
                return false;
        }
        col = d_col;
        while (row < n && col >= 0) {
            if (board[row++][col--] == 'Q')
                return false;
        }
        return true;
    }
    void solve(int &cnt, vector<string>& b, int col, int n) {
        if (col == n) {
            cnt++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, b, n)) {
                b[row][col] = 'Q';
                solve(cnt, b, col + 1, n);
                b[row][col] = '.';
            }
        }
    }
   
    int totalNQueens(int n) {
        int cnt=0;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(cnt, board, 0, n);
        return cnt;
    }
};