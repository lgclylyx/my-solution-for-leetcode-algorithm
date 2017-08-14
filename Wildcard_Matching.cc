/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
*/

/*

	DP: O(m*n),动态规划中的基本状态为vec[i][j]，s[0~i-1]和p[0~j-1]是否匹配

    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<bool>> vec(lens+1,vector<bool>(lenp+1,false));
        
        vec[0][0] = true;
        
        for(int i = 1; i <= lenp; i++) 
            vec[0][i] = ('*' == p[i-1] && vec[0][i-1]);
        
        for(int i = 1; i <= lens; i++){
            for(int j = 1; j <= lenp; j++){
                if('*' != p[j-1])
                    vec[i][j] = ('?' == p[j-1] || s[i-1] == p[j-1]) && vec[i-1][j-1];
                else
                    vec[i][j] = vec[i-1][j-1] || vec[i-1][j] || vec[i][j-1];
            }
        }
        
        return vec[lens][lenp]; 
    }
*/