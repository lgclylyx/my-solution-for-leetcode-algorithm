/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 
*/

/*

	DP algorithm,I don't know why it's right, but it's right.

    int numDistinct(string s, string t) {
        if(s.size() < t.size())
            return 0;
        if(!t.size())
            return 1;
        vector<vector<int>> dp(t.size(),vector<int>(s.size(),0));
        
        if(s[0] == t[0])
            dp[0][0] = 1;
        
        for(int j = 1; j < s.size(); j++)
            dp[0][j] = s[j] == t[0] ? dp[0][j-1] + 1 : dp[0][j-1];
        
        for(int i = 1; i < t.size(); i++)
            for(int j = i; j < s.size(); j++)
                dp[i][j] = s[j] == t[i] ? dp[i][j-1]+dp[i-1][j-1] : dp[i][j-1]; 
        
        return dp[t.size()-1][s.size()-1];
    }
*/