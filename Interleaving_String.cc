/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/

/*

	Time Limit Exceeded,but I think it's right.

    bool isInterleave(string s1, string s2, string s3) {
        int i = 0 , j = 0, k = 0;
        
        stack<int> st;
        
        while(true){
            if(k >= s3.size() || (i >= s1.size()&& j >= s2.size()))
               break;
            if(i < s1.size() && s1[i] == s3[k] && j < s2.size() && s2[j] == s3[k]){
                st.push(i);
                st.push(j);
                st.push(k);
                i++;
                k++;
            }else if(i < s1.size() && s1[i] == s3[k]){
                i++;
                k++;
            }else if(j < s2.size() && s2[j] == s3[k]){
                j++;
                k++;
            }else{
                if(st.empty())
                    return false;
                k = st.top();
                st.pop();
                j = st.top();
                st.pop();
                i = st.top();
                st.pop();
                j++;
                k++;
            }
        }
        if(k == s3.size() && i == s1.size() && j == s2.size())
            return true;
        else
            return false;
    }
*/

/*

	DP algorithm;s1中[0,i]和s2中[0,j]是否和s3中[0,i+j]相匹配

    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        
        vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1,true));
        
        for(int i = 0; i <= s1.size(); i++)
            for(int j = 0; j <= s2.size(); j++){
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
                else
                    dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) ||(dp[i-1][j] && (s1[i-1] == s3[i+j-1]));\\后一个状态的值从前一个状态中得出
            }
        return dp[s1.size()][s2.size()];
    }
*/

/*

another idea:

If we expand the two strings s1 and s2 into a chessboard, then this problem can be transferred into a path seeking problem from the top-left corner to the bottom-right corner. The key is, each cell (y, x) in the board corresponds to an interval between y-th character in s1 and x-th character in s2. And adjacent cells are connected with like a grid. A BFS can then be efficiently performed to find the path.

Better to illustrate with an example here:

Say s1 = "aab" and s2 = "abc". s3 = "aaabcb". Then the board looks like

o--a--o--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--o--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--o--b--o--c--o
|     |     |     |
b     b     b     b
|     |     |     |
o--a--o--b--o--c--o

Each "o" is a cell in the board. We start from the top-left corner, and try to move right or down. If the next char in s3 matches the edge connecting the next cell, then we're able to move. When we hit the bottom-right corner, this means s3 can be represented by interleaving s1 and s2. One possible path for this example is indicated with "x"es below:

x--a--x--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--x--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--x--b--x--c--x
|     |     |     |
b     b     b     b
|     |     |     |
o--a--o--b--o--c--x

Note if we concatenate the chars on the edges we went along, it's exactly s3. And we went through all the chars in s1 and s2, in order, exactly once.

Therefore if we view this board as a graph, such path finding problem is trivial with BFS. I use an unordered_map to store the visited nodes, which makes the code look a bit complicated. But a vector should be enough to do the job.

Although the worse case timeis also O(mn), typically it doesn't require us to go through every node to find a path. Therefore it's faster than regular DP than average.
*/