class Solution {
public:
    void bfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int row,int col, bool& possible, int &no_of_cells) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        int dr[] = {0, -1, 0, 1};
        int dc[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
             if (c== 0 || c == m-1 || r == 0 || r == n-1) {
                    possible = true;
                }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
               
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                    no_of_cells++;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    bool possible = false;
                    int cells = 1;
                    bfs(vis, grid, i, j, possible, cells);
                    if (!possible)
                        cnt += cells;
                }
            }
        }
        return cnt;
    }
};