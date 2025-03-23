class Solution {
public:
    void dfs(vector<vector<char>>& board, int cr, int cc) {
        int row = board.size();
        int col = board[0].size();
        
        if (cr < 0 || cr >= row || cc < 0 || cc >= col) 
            return;
        if(board[cr][cc] == 'T'|| board[cr][cc] == 'X')return;
        board[cr][cc] = 'T'; // Temporarily mark safe 'O' cells

        // Explore 4 directions
        dfs(board, cr + 1, cc);
        dfs(board, cr - 1, cc);
        dfs(board, cr, cc + 1);
        dfs(board, cr, cc - 1);
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();

        // Step 1: Mark all 'O's connected to borders as 'T'
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0||i==row-1||j==0||j==col-1)
                {
                    dfs(board,i,j);
                }
            }
        }
        // Step 2: Convert remaining 'O' to 'X' (these are the surrounded ones)
        // Step 3: Convert 'T' back to 'O' (these were border-connected)
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X'; // Surrounded 'O' becomes 'X'
                else if (board[i][j] == 'T') 
                    board[i][j] = 'O'; // Border-connected 'O' is restored
            }
        }
    }
};
