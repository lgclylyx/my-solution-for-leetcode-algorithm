/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*

	DP algorithm;所以可以用DP算法解决的问题都能更自然的想到用递归来解决，但DP更有效率。

    int numTrees(int n) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int count = 0;
            for(int j = 1; j <= i; j++){
                count += (dp[j-1] *dp[i - j]);
            }
            dp[i] = count;
        }
        return dp[n];
    }
*/