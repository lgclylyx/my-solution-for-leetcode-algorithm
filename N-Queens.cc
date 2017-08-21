/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

/*

	回退算法，相当于DFS

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string str(n,'.');
        vector<string> t(n,str);
        unordered_set<int> cols,skewl,skewr;
        solver(result,t,cols,skewl,skewr,n,0);
        return result;
    }
    
    void solver(vector<vector<string>>& result,vector<string>& t,unordered_set<int>& cols,unordered_set<int>& skewl,unordered_set<int>& skewr,int n, int i){
        if(i >= n){
            result.push_back(t);
            return;
        }
        
        for(int j = 0; j < n; j++){
            int posl = j - i;
            int posr = i + j;
            if(cols.find(j) == cols.end() && skewl.find(posl) == skewl.end() && skewr.find(posr) == skewr.end()){
                cols.insert(j);
                skewl.insert(posl);
                skewr.insert(posr);
                t[i][j] = 'Q';
                solver(result,t,cols,skewl,skewr,n,i+1);
                t[i][j] = '.';
                skewr.erase(posr);
                skewl.erase(posl);
                cols.erase(j);
            }
        }
    }
*/