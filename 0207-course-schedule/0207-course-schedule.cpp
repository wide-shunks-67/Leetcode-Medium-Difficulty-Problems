class Solution {
public:
    bool dfs(int src, vector<int>& vis, vector<int>& path,
             vector<vector<int>>& adj) {
        vis[src] = 1;
        path[src] = 1;
        for (auto it : adj[src]) {
            if (!vis[it]) {
                if(dfs(it, vis, path, adj))return true;
            } else if (path[it])
                return true;
        }
        path[src] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<vector<int>> adj(numCourses);
        vector<vector<int>> p = prerequisites;
        for (int i = 0; i < n; i++) {
            int u = p[i][0];
            int v = p[i][1];
            adj[v].push_back(u);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);

        for (int i = 0; i < vis.size(); i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj))
                    return false;
            }
        }
        return true;
    }
};