/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input: 
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
*/

/*

    dp[k][i]代表将A[0,i]分为k个组时的最大值，则dp[k][i] = max(dp[k][j]+(sum[i]-sum[j])/(i-j),dp[i][j])，j属于[k-2,i),这样就能确保
    其能够满足分段的要求。A[0,k-2]能够确保能够分出k-1个段，而j < i，能够保证[j+1,i]能够分出一个段。

    double largestSumOfAverages(vector<int>& A, int K) {
        if(A.empty() || K == 0)
            return 0;
        vector<vector<double>> dp(K+1,vector<double>(A.size(),0));
        vector<int> sum;
        sum.push_back(A[0]);
        for(int i = 1; i < A.size(); i++)
            sum.push_back(A[i] + sum.back());
        
        for(int k = 1; k <= K; k++){
            for(int i = k-1; i < A.size(); i++){
                if(k == 1)
                    dp[k][i] = double(sum[i])/(i+1);
                else{
                    for(int j = k-2 ; j < i; j++){
                        dp[k][i] = max(dp[k-1][j] + double(sum[i] - sum[j]) / (i - j),dp[k][i]);
                    }
                }
            }
        }
        return dp[K][A.size()-1];
    }
*/
