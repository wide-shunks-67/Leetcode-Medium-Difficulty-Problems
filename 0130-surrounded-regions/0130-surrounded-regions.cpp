class Solution {
public:
void marksafe(int r,int c,vector<vector<char>>& board){
    int n= board.size();
    int m= board[0].size();
    if(r<0 || r>=n || c<0 || c>=m || board[r][c]!='O'){
        return ;
    }
    board[r][c] = '#';
    marksafe(r+1,c,board);
    marksafe(r-1,c,board);
    marksafe(r,c+1,board);
    marksafe(r,c-1,board);
}
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        for(int row=0;row<n;row++){
            marksafe(row,0,board);
            marksafe(row,m-1, board);
        }
        for(int col=0;col<m;col++){
            marksafe(0,col,board);
            marksafe(n-1,col,board);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};