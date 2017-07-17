/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
*/

/*

    使用栈，O(n)，栈中保存的是'('在字符串中的位置，栈底保存的是可能合法的子串的开始位置

    int longestValidParentheses(string s) {
        if(s.size() <= 1)
            return 0;
        stack<int> sc;
        sc.push(-1);
        int maxlen = 0;
        for(int i = 0; i < s.size(); i++){
            if('(' == s[i])
                sc.push(i);
            else{
                sc.pop();
                if(sc.empty())
                    sc.push(i);
                else{
                    int len = i - sc.top();
                    if(len > maxlen)
                        maxlen = len;
                }
            }
        }
        return maxlen;
    }
*/

/*

    使用动态规划解决，O(n)，dp[0]=0，当i位置为‘(‘时，dp[i]=0，当s[i]=')'时，才有可能匹配，若s[i-1]为’(‘，则dp[i]为在dp[i-2]的基础上
    加2，若dp[i-1]=')'，则dp[i]为，dp[i-dp[i-1]-1]='('时，dp[i-1] + dp[i-dp[i-1]-2]+2

    int longestValidParentheses(string s) {
        if(s.size() <= 1)
            return 0;
        vector<int> dp(s.size());
        dp[0] = 0;
        for(int i = 1; i < s.size(); i++){
            if(')' == s[i]){
                if('(' == s[i-1])
                    dp[i] = dp[i-1] +(i-2 >= 0 ? dp[i-2] : 0) + 2;
                else if(i > dp[i-1] && '(' == s[i-dp[i-1]-1])
                    dp[i] = dp[i-1] + (i - dp[i-1] -2 >= 0 ? dp[i-dp[i-1]-2] : 0) + 2;
            }
        }
        return *(max_element(dp.begin(),dp.end()));
    }
*/
