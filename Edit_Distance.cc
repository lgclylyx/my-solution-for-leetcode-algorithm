/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

/*

	DP algorithm

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));

        for(int i = 1; i < word2.size()+1; i++)
            dp[0][i] = dp[0][i-1] + 1;
        for(int i = 1; i < word1.size()+1; i++)
            dp[i][0] = dp[i-1][0] + 1;
        
        for(int i = 0; i < word1.size(); i++)
            for(int j = 0;j < word2.size(); j++){
                if(word1[i] == word2[j])
                    dp[i+1][j+1] = dp[i][j];
                else
                    dp[i+1][j+1] = min(dp[i][j],min(dp[i+1][j],dp[i][j+1])) + 1;
            }
        
        return dp[word1.size()][word2.size()];
    }
*/