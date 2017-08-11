/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. 
*/


/*

	bruteforce:使用回退算法，从左至右，从上至下的对每个应填位置的每种可能位置进行遍历

    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> blocks(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if('.' == c)
                    continue;
                int pos = (i/3)*3 + j/3;
                rows[i].insert(c);
                cols[j].insert(c);
                blocks[pos].insert(c);
            }
        }
        solver(board,rows,cols,blocks,0,0);
    }
    bool solver(vector<vector<char>>& board,vector<unordered_set<char>>& rows,vector<unordered_set<char>>& cols,vector<unordered_set<char>>& blocks,int i, int j){
        vector<char> candi;
        if(i < 9){
            for(;j < 9;j++)
                if('.' == board[i][j])
                    break;
            if(j >= 9){
                if(!solver(board,rows,cols,blocks,i+1,0))
                    return false;
            }else{
                int pos = (i/3)*3 + j/3;
                for(char k = '1'; k <= '9'; k++)
                    if(rows[i].find(k) == rows[i].end() && cols[j].find(k) == cols[j].end() && blocks[pos].find(k) == blocks[pos].end())
                        candi.push_back(k);
                while(!candi.empty()){
                    char c = candi.front();
                    rows[i].insert(c);
                    cols[j].insert(c);
                    blocks[pos].insert(c);
                    board[i][j] = c;
                    candi.erase(candi.begin());
                    if(!solver(board,rows,cols,blocks,i,j+1)){
                        rows[i].erase(rows[i].find(c));
                        cols[j].erase(cols[j].find(c));
                        blocks[pos].erase(blocks[pos].find(c));
                        board[i][j] = '.';
                    }else
                        return true;
                }
                return false;
            }
        }
        return true;
    }

*/