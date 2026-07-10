class Solution {
public:
    bool dfs(vector<vector<char>>& b, string& word, int i, int j, int index) {
        if (index == word.length())
            return true;
        if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size() ||
            b[i][j] != word[index])
            return false;
        char temp = b[i][j];
        b[i][j] = '#';
        bool found = dfs(b, word, i, j + 1, index + 1) ||
                     dfs(b, word, i + 1, j, index + 1) ||
                     dfs(b, word, i - 1, j, index + 1) ||
                     dfs(b, word, i, j - 1, index + 1);
        b[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i ,j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};