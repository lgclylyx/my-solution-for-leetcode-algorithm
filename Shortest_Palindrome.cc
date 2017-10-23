/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/



/*

	该问题实质上是求一个串的包括开头字符的最长回文串。

	该解法，固定使用O(N^2)的时间和空间，solw!!

    string shortestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        int n = s.size();
        int l = 0, r = n-1;
        int maxl = 1;
        vector<vector<bool>> pal(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j = n-1; j >= i; j--){
                if(s[i]==s[j] && (j-i<2 || pal[i+1][j-1])){
                    pal[i][j]=true;
                }
            }
        }
        
        while(r >= 0 && !pal[l][r])
            r--;
        
        r++;
        string t = s.substr(r,n - r);
        reverse(t.begin(),t.end());
        s = t + s;
        
        return s;
    }
*/

/*

	改进，该算法使用O(1)的空间，最好的情况下，O(1)的时间，最坏的情况下，O(n^2)，还是slow！！！

    string shortestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        int n = s.size();
        int low , high;
        for(int j=n-1;j>=0;j--){
            if(( j + 1) % 2 == 0){
                low = j / 2;
                high = low + 1;
            }else{
                low = high = j / 2;
            }
            for(;low >= 0 && high <= j && s[low] == s[high]; low--, high++);
            if(low < 0)
                break;
        }
        string t = s.substr(high,n - high);
        reverse(t.begin(),t.end());
        s = t + s;
        
        return s;
    }
*/

/*

	给予KMP算法的方法。将模式串转置并将两个串放置在一起（ori_str#rev_str）。则对于next[size() - 1]，则为
	该模式串的包括串头的最长回问串长度。

    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }
        
        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
*/