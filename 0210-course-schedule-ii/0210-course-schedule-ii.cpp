class Solution {
public:
bool dfs(int src, vector<int> &vis,vector<int>&path, stack<int>&s, vector<vector<int>>&adj){
    vis[src]=1;
    path[src]=1;
    for(auto it:adj[src]){
        if(!vis[it]){
            if(dfs(it,vis,path,s,adj))return true;
        }
        else if(path[it])return true;
    }
    s.push(src);
    path[src]=0;
    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> p = prerequisites;
        int n = numCourses;
        vector<int>path(n,0);
        vector<int> vis(n, 0);
        stack<int> s;
        vector<vector<int>> adj(n);
        for (int i = 0; i < p.size(); i++) {
            int u = p[i][0];
            int v = p[i][1];
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if(dfs(i, vis,path, s, adj))return {};
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};