/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
*/

/*

		DP algorithm; pal[i,j]表示s[i,j]是否是一个回文串；d[i]代表s[i,n-1]的最小cut

        int minCut(string s) {
            if(s.empty()) return 0;
            int n = s.size();
            vector<vector<bool>> pal(n,vector<bool>(n,false));
            vector<int> d(n);
            for(int i=n-1;i>=0;i--){
                d[i]=n-i-1;//对于s[i,n-1]的最大cut是n-1-i
                for(int j=i;j<n;j++){
                    if(s[i]==s[j] && (j-i<2 || pal[i+1][j-1])){//s[i,j]是否是回文串能从s[i+1,j-1]得到
                       pal[i][j]=true;
                       if(j==n-1)
                           d[i]=0;
                       else if(d[j+1]+1<d[i]）\\如果s[i,j]是回文串，则s[i,n-1]的最小cut为1+ d[j+1]
                           d[i]=d[j+1]+1;
                    }
                }
            }
            return d[0];
        }
*/