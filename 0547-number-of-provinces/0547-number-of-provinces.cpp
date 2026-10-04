class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int connections=0;
        vector<bool>visited(n,false);
        for(int start=0;start<n;start++){
            if(visited[start])continue;
            connections++;
            queue<int>q;
            q.push(start);
            visited[start]=true;
            while(!q.empty()){
                int front= q.front();
                q.pop();
                for(int i:adj[front]){
                    if(!visited[i]){
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }
        }
        return connections;
    }
};