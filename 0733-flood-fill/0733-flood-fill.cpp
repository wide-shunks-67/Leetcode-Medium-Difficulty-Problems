class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og= image[sr][sc];
        
        int n= image.size();
        int m= image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=color;
        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            image[r][c]=color;
            for(int i=0;i<4;i++){
                int newr= r+dr[i];
                 int newc=  c + dc[i];
                  if(newr>=0&&newr<n && newc>=0&& newc<m && image[newr][newc]==og && !vis[newr][newc]){
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                  }
            }
        }
        return image;
    }
};