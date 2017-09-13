/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/

/*

	DP algorithm

    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        vector<int> dp(s.size()+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1; i < s.size(); i++){
            int num = (s[i-1] - '0') * 10 + s[i] - '0';
            if(s[i] == '0'){//当为0时，只能与前一个数组合成一个两位数
                if(num <= 26)
                    if(s[i-1] == '0')
                        dp[i+1] = 0;
                    else
                        dp[i+1] = dp[i-1];
                else
                    dp[i+1] = 0;
            }else{//当不为0时，则有两种选择
                if(num <= 26)//当能组成两位数时
                    if(s[i-1] == '0')
                        dp[i+1] = max(0,dp[i]);
                    else
                        dp[i+1] = dp[i] + dp[i-1];
                else//不能组成时
                    dp[i+1] = dp[i];
            } 
        }
        return dp[s.size()];
    }
*/