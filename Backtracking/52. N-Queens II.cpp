class Solution {
public:
    vector<vector<bool>>  board;
    
    bool issafe(int row,int col,int n)
    {
        
        for(int i=0;i<col;i++)
            if(board[row][i])return false;
        
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
            if(board[i][j])return false;
        
        for(int i=row,j=col;i<n && j>=0; i++,j--)
            if(board[i][j])return false;
        
        return true;
        
    }
    
    int solve(int col,int n)
    {
        if(col==n)return 1;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(issafe(i,col,n))
            {
                board[i][col]=1;
                ans+=solve(col+1,n);
                board[i][col]=0;
            }
        }
        
        return ans;
    }
    
    int totalNQueens(int n) {
        board.resize(n,vector<bool>(n,0));
        
        
        return solve(0,n);
    }
};
