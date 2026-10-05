class Solution {
public:
    void bfs(vector<vector<int>>& vis, vector<vector<char>>& grid, int row,
             int col) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int j = 0; j <4 ; j++) {
                int new_row = r+ dr[j];
                int new_col = c+ dc[j];
                if (new_row >= 0 && new_row < n && new_col >= 0 &&
                    new_col < m && grid[new_row][new_col] == '1' &&
                    !vis[new_row][new_col]) {
                    vis[new_row][new_col] = 1;
                    q.push({new_row, new_col});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(vis, grid, i, j);
                } else
                    continue;
            }
        }
        return cnt;
    }
};