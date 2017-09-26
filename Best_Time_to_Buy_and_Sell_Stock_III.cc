/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

/*

	// f[k, ii] represents the max profit up until prices[ii]  using at most k transactions. 
    // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj])  jj = 0..ii-1
    //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))  jj = 0..ii-1
    //tepMax = max(f[k - 1][jj] - prices[jj])
    // f[0, ii] = 0; 0 times transation makes 0 profit
    // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade

    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        else {
            int K = 2; 
            int maxProf = 0;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= K; kk++) {
                tempmax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]); //本应该遍历所有0..ii-1的位置找到最大的f[kk-1][ii] - prices[ii]，但是tepMax已经是ii后面所有情况的最大值，则不用继续遍历了
                    maxProf = max(f[kk][ii], maxProf);
                }
            }
            return maxProf;
        }
    }
*/