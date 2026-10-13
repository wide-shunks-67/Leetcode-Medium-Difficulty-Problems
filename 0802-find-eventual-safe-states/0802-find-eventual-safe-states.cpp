class Solution {
public:
bool dfs(int src, vector<int>&vis, vector<vector<int>>& graph){
    if(vis[src]==1)return false;
    if(vis[src]==2)return true;
     vis[src]=1;
    for(int node:graph[src]){
        if(!dfs(node,vis,graph))return false;
    }
    vis[src]=2;
    return true;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        
        vector<int>ans;
         vector<int>vis(n,0);
         for(int i=0;i<n;i++){
            if(dfs(i,vis,graph)){
                ans.push_back(i);
            }
         }
         return ans;
    }
};