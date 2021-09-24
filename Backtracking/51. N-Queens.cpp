class Solution {
public:
    vector<string> board;
    vector<vector<string>> sol;
    bool issafe(int row,int col,int n)
    {
        for(int i=0;i<col;i++)
            if(board[row][i]=='Q')return false;
        
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
            if(board[i][j]=='Q')return false;
    
        for(int i=row,j=col;i<n && j>=0;i++,j--)
            if(board[i][j]=='Q')return false;
        
        return true;
        
    }
    
    void solve(int col,int n)
    {
        if(col==n){
            sol.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(issafe(i,col,n))
            {
                board[i][col]='Q';
                solve(col+1,n);
                board[i][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string s;
        for(int i=0;i<n;i++)s+=".";
        for(int i=0;i<n;i++)board.push_back(s);
        
        solve(0,n);
        return sol;
    }
};
