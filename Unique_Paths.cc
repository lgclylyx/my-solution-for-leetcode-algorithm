/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

/*

	DP algorithm,O(m*n). there is also mathematical way to solve this question.for (3,7),we must have 8 eight operation to reach the destination., 2 down and 6 right. so the
	all paths are the eight operations' permutations. so all the paths equal to (m-1 + n-1)! / ((m-1)! * (n-1)!). the purpose of dividing ((m-1)! * (n-1)!) is to remove the same
	paths.

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i++)
            dp[i][n-1] = 1;
        for(int i = 0; i < n; i++)
            dp[m-1][i] = 1;
        for(int i = m-2; i >= 0; i--)
            for(int j = n-2; j >= 0; j--)
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
        return dp[0][0];
    }
*/