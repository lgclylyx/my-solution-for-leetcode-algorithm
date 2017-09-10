/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/*

	backtracking algorithm;

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = rows == 0 ? 0 : board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                bool flag = solver(board,word,i,j,0);
                if(flag)
                    return true;
            }
        }
        return false;
    }
    
    bool solver(vector<vector<char>>& board, string& word, int m, int n ,int i){
        if(m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] == '\0' || word[i] != board[m][n])
            return false;
        if(i == word.size() - 1)
            return true;
        char t = board[m][n];
        board[m][n] = '\0';
        if(solver(board,word,m+1,n,i+1) || solver(board,word,m,n+1,i+1) || solver(board,word,m-1,n,i+1) || solver(board,word,m,n-1,i+1))
            return true;
        board[m][n] = t;
        return false;
    }
*/