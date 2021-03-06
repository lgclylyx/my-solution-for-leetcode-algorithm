/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9. 
*/

/*

	DP.dp[i],代表的是值i的最小次数。
	实际上这相当于一个递归的过程的正过程。
	
	(1)dp[i]表示值为i时需要的数的最小数目；
	(2)已知选择K可以从上一步导致dp[i]；
	(3)则dp[i]可以由子问题dp[i-K]推到得到；
	(4)证明dp[i-K]是子问题的最优解；
	(5)所以最优子结构dp[i] = min(dp[i],dp[i-K]+1),所以在原问题中只使用一个子问题和在决定一个最优解中使用哪个子问题时有[1^2,sqrt(i)^2]种选择

    int numSquares(int n) {
        if(n <= 0)
            return 0;
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = sqrt(i); j >= 1; j--){
                dp[i] = min(dp[i],dp[i - j*j] + 1);
            }
        }
        return dp.back();
    }
*/

/*

	BFS.将所有的解的集合看做一张图，使用BFS在其中找到一条
	通往目标节点的最短路径。

    int numSquares(int n) {
        int count = 0, len;
        queue<int> que;
        que.push(n);
        len = que.size();
        while(!que.empty()){
            int t = que.front();
            que.pop();
            len --;
            int i = sqrt(t);
            for(; i >= 1;i--){
                int tt = t - i*i;
                if(tt == 0)
                    break;

                que.push(tt);
            }
            if(i != 0){
                count++;
                break;
            }
            if(len == 0){
                len = que.size();
                count++;
            }
        }
        return count;
    }
*/
